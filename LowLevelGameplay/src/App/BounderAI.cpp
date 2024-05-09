#include "Core/BounderAI.h"
#include "Core/Player.h"
#include "Core/Vector2.h"
#include "Core/ColliderTypes.h"

LLGP::BounderAI::~BounderAI()
{
	//_GameObject->sceneManager->Update.RemoveListener(this, std::bind(&BounderAI::Update, this, std::placeholders::_1));
	//_GameObject->sceneManager->FixedUpdate.RemoveListener(this, std::bind(&BounderAI::FixedUpdate, this, std::placeholders::_1));
	parentRef = nullptr;
}

void LLGP::BounderAI::OnCollisionEnter(GameObject* other)
{
	//check if hit lower half or upper half 
	if (other->GetTag() == "Player")
	{
		AABBCollider* playerCollider = other->GetComponent<AABBCollider>();
		AABBCollider* collider = _GameObject->GetComponent<AABBCollider>();

		float playerMidpoint = other->transform.position.y + (playerCollider->height / 2);
		float midpoint = _GameObject->transform.position.y + (collider->height / 2);

		if (playerMidpoint < midpoint) 
		{
			//player wins collision
			bounderState = DROPEGG;
		}
	}
}

void LLGP::BounderAI::Start()
{
	parentRef = static_cast<Enemy*>(_GameObject);
	bounderState = PATROL_RIGHT;
	//add functions to events. 
	_GameObject->sceneManager->Update.AddListener(this, std::bind(&BounderAI::Update, this, std::placeholders::_1));
	_GameObject->sceneManager->FixedUpdate.AddListener(this, std::bind(&BounderAI::FixedUpdate, this, std::placeholders::_1));
}

void LLGP::BounderAI::Update(float deltaTime)
{
	switch (bounderState) 
	{
	case PATROL_LEFT:
		PerformPatrolLeft(deltaTime);
		break;
	case PATROL_RIGHT:
		PerformPatrolRight(deltaTime);
		break;
	case MOVEPOSITION:
		PerformMovePosition(deltaTime);
		break;
	case DROPEGG:
		PerformDropEgg();
		break;
	}
}


void LLGP::BounderAI::FixedUpdate(float fixedDeltaTime) //untested
{ 
	//calculate player movement 
	Vector2<float> playerCurPos = parentRef->_player->transform.position;
	float movement = playerCurPos.Distance(playerCurPos, playerPrevPos);
	playerPrevPos = playerCurPos;

	if (movement > movementArea) 
	{
		framesSinceLastGoodMovement++;
		if (framesSinceLastGoodMovement > 50 * 10) 
		{
			bounderState = MOVEPOSITION;
		}
		return;
	}
	framesSinceLastGoodMovement = 0;
}

void LLGP::BounderAI::PerformPatrolLeft(float deltaTime)
{
	//move left along height level until hit far left then turn around
	_GameObject->transform.position.x -= _speed *deltaTime;

	//transition
	if (_GameObject->transform.position.x <= 0) 
	{
		bounderState = PATROL_RIGHT;
	}
}

void LLGP::BounderAI::PerformPatrolRight(float deltaTime)
{
	//move right along height level until hit far right then turn round
	_GameObject->transform.position.x += _speed *deltaTime;

	//transition 
	if (_GameObject->transform.position.x >= 640) 
	{
		bounderState = PATROL_LEFT;
	}
}

void LLGP::BounderAI::PerformMovePosition(float deltaTime)
{
	//if the player stays in one area for a long time then move height level 

	//transition - if at the target position then turn
}

void LLGP::BounderAI::PerformDropEgg()
{
	//drop the egg
	//destory self 
}
