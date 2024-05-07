//#include "Core/BounderAI.h"
//#include "Core/Player.h"
//
//void LLGP::BounderAI::OnCollisionEnter(GameObject* other)
//{
//}
//
//void LLGP::BounderAI::Start()
//{
//	parentRef = static_cast<Enemy*>(_GameObject);
//	//add functions to events. 
//	_GameObject->sceneManager->Update.AddListener(this, std::bind(&BounderAI::Update, this, std::placeholders::_1));
//	_GameObject->sceneManager->FixedUpdate.AddListener(this, std::bind(&BounderAI::FixedUpdate, this, std::placeholders::_1));
//}
//
//void LLGP::BounderAI::Update(float deltaTime)
//{
//	switch (bounderState) 
//	{
//	case PATROL_LEFT:
//		PerformPatrolLeft();
//		break;
//	case PATROL_RIGHT:
//		PerformPatrolRight();
//		break;
//	case MOVEPOSITION:
//		PerformMovePosition();
//		break;
//	case DROPEGG:
//		PerformDropEgg();
//		break;
//	}
//}
//
////Vector2<float> playerPrevPos; //players position in the prev frame 
////float movementArea = 10; //min movement amount per frame to not be counted as idle 
////int framesSinceLastGoodMovement; //how many frames since player moved in a bigger motion than movement area 
//
//void LLGP::BounderAI::FixedUpdate(float fixedDeltaTime)
//{ 
//	//calculate player movement 
//	Vector2<float> playerCurPos = parentRef->_player->transform.position;
//	float movement = parentRef->_player
//	
//}
//
//void LLGP::BounderAI::PerformPatrolLeft()
//{
//	//move left along height level until hit far left then turn around
//}
//
//void LLGP::BounderAI::PerformPatrolRight()
//{
//	//move right along height level until hit far right then turn round
//}
//
//void LLGP::BounderAI::PerformMovePosition()
//{
//	//if the player stays in one area for a long time then move height level 
//}
//
//void LLGP::BounderAI::PerformDropEgg()
//{
//}
