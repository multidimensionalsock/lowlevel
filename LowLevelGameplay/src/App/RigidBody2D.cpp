#include "Core/RigidBody2D.h"
#include "Core/GameObject.h"
#include "Core/ColliderTypes.h"
#include <iostream>
#define GRAVITY 0.01f //meters per second 

void LLGP::RigidBody2D::FixedUpdate(float fixedDeltaTime)
{
	if (!colliding)
	{
		float gravity = GRAVITY;
		_force.y += gravity;
		
		//_transform->position.y += gravity;
	}
	
	_velocity = (_force / _mass) * fixedDeltaTime;
	_transform->position += _force;
	ClearForce();

	//need to add a drag force to slow it in some place but LATER ISSUES
}


void LLGP::RigidBody2D::OnCollisionEnter(GameObject* other)
{
	std::cout << _GameObject->GetTag() << " is colliding with " << other->GetTag() << std::endl;
	if (other->CompareTag("Floor")) {
		AABBCollider* othercollider = other->GetComponent<AABBCollider>();
		AABBCollider* collider = _GameObject->GetComponent<AABBCollider>();
		if (othercollider != nullptr && collider != nullptr)
		{
			if (abs(othercollider->position.y - (collider->position.y + collider->height)) > 1)
			{
				colliding = false;
				return;
			}
		}
	}
	colliding = true; 
}

void LLGP::RigidBody2D::OnCollisionExit(GameObject* other)
{
	if (_GameObject->_collidingWith.empty())
		colliding = false;
}

LLGP::RigidBody2D::RigidBody2D(GameObject* owner)
{
	colliding = false;
	_GameObject = owner;
	
	owner->sceneManager->Update.AddListener(this, std::bind(&RigidBody2D::Update, this, std::placeholders::_1));
	owner->sceneManager->FixedUpdate.AddListener(this, std::bind(&RigidBody2D::FixedUpdate, this, std::placeholders::_1));

	_velocity = Vector2<float>::zero;
	_force = Vector2<float>::zero;
}




