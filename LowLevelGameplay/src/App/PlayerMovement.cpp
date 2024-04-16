#include "Core/PlayerMovement.h"
#include "Core/GameObject.h"
#include "Core/Vector2.h"

LLGP::PlayerMovement::PlayerMovement(GameObject* owner)
{
	_GameObject = owner; 

	_GameObject->sceneManager->Update += std::bind(&PlayerMovement::Update, this, std::placeholders::_1);
	_GameObject->sceneManager->FixedUpdate += std::bind(&PlayerMovement::FixedUpdate, this, std::placeholders::_1);
	rigidBody = _GameObject->GetComponent<RigidBody2D>();
	inputHandler = new InputHandling();
	inputHandler->Left += std::bind(&PlayerMovement::MoveLeft, this, std::placeholders::_1);
	inputHandler->Right += std::bind(&PlayerMovement::MoveRight, this, std::placeholders::_1);
	inputHandler->Up += std::bind(&PlayerMovement::MoveUp, this, std::placeholders::_1);
}

void LLGP::PlayerMovement::Update(float deltaTime)
{
	
}

void LLGP::PlayerMovement::FixedUpdate(float fixedDeltaTime)
{
	inputHandler->PollInputs();
	if (movingUp) 
	{
		rigidBody->AddForce(Vector2<float>(0, -1));
	}
	if (movingLeft) 
	{
		rigidBody->AddForce(Vector2<float>::left * playerSpeed);
	}
	if (movingRight) 
	{
		rigidBody->AddForce(Vector2<float>::right * playerSpeed);
	}
}
