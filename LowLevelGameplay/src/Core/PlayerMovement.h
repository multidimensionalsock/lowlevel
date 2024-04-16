#pragma once 
#include "Core/MonoBehaviour.h"
#include "Core/InputHandling.h"
#include "Core/RigidBody2D.h"

namespace LLGP 
{
	class PlayerMovement : public MonoBehaviour 
	{
	public:
		PlayerMovement(GameObject* owner);
		~PlayerMovement() {};

		void MoveLeft(bool left) { movingLeft = left; }
		void MoveRight(bool right) { movingRight = right; }
		void MoveUp(bool up) { movingUp = up; }

		//use inputs to affect rigidbody 
		void Update(float deltaTime) override; // called every frame
		void FixedUpdate(float fixedDeltaTime) override;
		float playerSpeed = 0.1f;

	private:
		bool movingLeft = false; 
		bool movingRight = false; 
		bool movingUp = false;
		
		InputHandling* inputHandler; 
		RigidBody2D* rigidBody;
	};
}
