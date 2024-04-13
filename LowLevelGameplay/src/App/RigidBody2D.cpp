#include "Core/RigidBody2D.h"
#include "Core/GameObject.h"
#define GRAVITY 0.098f //meters per second 

void LLGP::RigidBody2D::Update(float deltaTime)
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


