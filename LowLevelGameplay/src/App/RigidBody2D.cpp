#include "Core/RigidBody2D.h"
#include "Core/GameObject.h"
#define GRAVITY 9.8f //meters per second 

void LLGP::RigidBody2D::Update(float deltaTime)
{
	//add gravity 
	AddForce(Vector2<float>(0, (_mass * GRAVITY)));
	//update velocity 
	_velocity = (_force / _mass) * deltaTime;
	
	//update position 
	_transform->position += _velocity * deltaTime;

	std::cout << _force.y << std::endl; 
	
}

void LLGP::RigidBody2D::FixedUpdate(float fixedDeltaTime)
{
}

LLGP::RigidBody2D::RigidBody2D(GameObject* owner)
{
	_GameObject = owner;
	
	owner->sceneManager->Update += std::bind(&RigidBody2D::Update, this, std::placeholders::_1);
	owner->sceneManager->FixedUpdate += std::bind(&RigidBody2D::FixedUpdate, this, std::placeholders::_1);

	_velocity = Vector2<float>::zero;
	_force = Vector2<float>::zero;
}


