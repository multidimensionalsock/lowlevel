#include "Core/RigidBody2D.h"
#include "Core/GameObject.h"
#define GRAVITY 0.098f //meters per second 

void LLGP::RigidBody2D::FixedUpdate(float fixedDeltaTime)
{
	float gravity = (_mass * 0.0098f);
	_force += Vector2<float>::up * gravity;
	_velocity = (_force / _mass);
	_transform->position += _velocity * fixedDeltaTime;

	//need to add a drag force to slow it in some place but LATER ISSUES
}

LLGP::RigidBody2D::RigidBody2D(GameObject* owner)
{
	_GameObject = owner;
	
	owner->sceneManager->Update += std::bind(&RigidBody2D::Update, this, std::placeholders::_1);
	owner->sceneManager->FixedUpdate += std::bind(&RigidBody2D::FixedUpdate, this, std::placeholders::_1);

	_velocity = Vector2<float>::zero;
	_force = Vector2<float>::zero;
}




