#pragma once 
#include "Core/MonoBehaviour.h"
#include "Core/Vector2.h"
#include "Core/Structs.h"

namespace LLGP
{
	class GameObject; 

	class RigidBody2D : public MonoBehaviour
	{
	private:
		float _mass = 1.0f;
		Vector2<float> _velocity;
		Vector2<float> _force;
		Transform* _transform; 

		void Update(float deltaTime) override; // called every frame
		void FixedUpdate(float fixedDeltaTime);
		

	public: 
		RigidBody2D(GameObject* owner);
		void SetTransform(Transform* transform) { _transform = transform; }

		Vector2<float> GetVelocity() { return _velocity; }

		float GetMass() { return _mass; }

		void SetMass(float mass) { _mass = mass; }

		void ClearForce()
		{
			_force = Vector2<float>::zero;
		}

		void SetForce(Vector2<float> force)
		{
			_force = force;
		}

		void AddForce(Vector2<float> force)
		{
			_force += force;
			std::cout << _force.x << ", " << _force.y << std::endl;
		}

		
	};
}
