#include "Core/PlayerMovement.h"
#include "Core/GameObject.h"
#include "Core/Vector2.h"

LLGP::PlayerMovement::PlayerMovement(GameObject* owner)
{
	_GameObject = owner; 

	_GameObject->sceneManager->Update.AddListener(this, std::bind(&PlayerMovement::Update, this, std::placeholders::_1));
	_GameObject->sceneManager->FixedUpdate.AddListener(this, std::bind(&PlayerMovement::FixedUpdate, this, std::placeholders::_1));
	rigidBody = _GameObject->GetComponent<RigidBody2D>();
	inputHandler = new InputHandling();
	inputHandler->Left.AddListener(this, std::bind(&PlayerMovement::MoveLeft, this, std::placeholders::_1));
	inputHandler->Right.AddListener(this, std::bind(&PlayerMovement::MoveRight, this, std::placeholders::_1));
	inputHandler->Up.AddListener(this, std::bind(&PlayerMovement::MoveUp, this, std::placeholders::_1));
}

void LLGP::PlayerMovement::Update(float deltaTime)
{
	
}

void LLGP::PlayerMovement::FixedUpdate(float fixedDeltaTime)
{
	inputHandler->PollInputs();
	if (movingUp) 
	{
		rigidBody->AddForce(Vector2<float>(0, -30));
		movingUp = false;
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
