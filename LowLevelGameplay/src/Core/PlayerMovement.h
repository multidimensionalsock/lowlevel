#pragma once 
#include "Core/MonoBehaviour.h"
#include "Core/InputHandling.h"

namespace LLGP 
{
	class PlayerMovement : MonoBehaviour 
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

	private:
		bool movingLeft; 
		bool movingRight; 
		bool movingUp;
		
		InputHandling* inputHandler; 
	};
}
