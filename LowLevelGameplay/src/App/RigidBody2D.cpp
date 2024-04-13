#include "Core/RigidBody2D.h"
#include "Core/GameObject.h"
#define GRAVITY 0.098f //meters per second 

void LLGP::RigidBody2D::Update(float deltaTime)
{
	//add gravity 
	float gravity =  (_mass * GRAVITY);
	_force.y += gravity;
	//when up ia pressed force y needs setting to zero 
	// for soem reason its setting x and y to force>> 
	//update velocity 
	_velocity = (_force / _mass);
	
	//update position 
	//_transform->position += _velocity * deltaTime;

	//std::cout << _velocity.x << ", " << _velocity.y << std::endl;
	
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


