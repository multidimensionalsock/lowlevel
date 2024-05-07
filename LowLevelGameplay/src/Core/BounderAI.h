//#pragma once
//#include "Core/Vector2.h"
//#include "Core/MonoBehaviour.h"
//#include "Core/GameObject.h"
//#include "Core/Enemy.h"
//
//
///*
//* Bounder – bounders are the basic enemy class in the game, acting to patrol the stage. 
//Bounders usually stay at a set height which they patrol but will move up or down if 
//they realise the player has stayed in a certain area for a period of time. When a bounder 
//is knocked off its mount an egg is dropped which if not picked up will become a hunter.  
//*/
//namespace LLGP
//{
//	enum BounderStates
//	{
//		PATROL_LEFT,
//		PATROL_RIGHT,
//		MOVEPOSITION,
//		DROPEGG
//	};
//
//	class BounderAI : public MonoBehaviour
//	{
//	public:
//		BounderAI(GameObject* owner) { _GameObject = owner; Start();  };
//
//		void OnCollisionEnter(GameObject* other) override;
//		//void OnCollisionExit(GameObject* other) override;
//
//	private:
//		void Start();
//		void Update(float deltaTime) override; 
//		void FixedUpdate(float fixedDeltaTime) override;
//
//		//state functions
//		void PerformPatrolLeft();
//		void PerformPatrolRight();
//		void PerformMovePosition();
//		void PerformDropEgg();
//
//		//track player movement 
//		Vector2<float> playerPrevPos; //players position in the prev frame 
//		float movementArea = 10; //min movement amount per frame to not be counted as idle 
//		int framesSinceLastGoodMovement; //how many frames since player moved in a bigger motion than movement area 
//
//		Enemy* parentRef;
//		Vector2<float> _patrolHeight;
//		BounderStates bounderState;
//	};
//}

