#pragma once
#include "Core/Vector2.h"
#include "Core/MonoBehaviour.h"
#include "Core/Transform.h"

namespace LLGP
{
	class Rigidbody2D : public MonoBehaviour
	{
	public:
		LLGP::Vector2<float> _velocity;
		LLGP::Vector2<float> _force;
		float _mass;
		LLGP::Vector2<float> _maxVelocity;
		Transform* _objectTransform;

		void FixedUpdate(float fixedDeltaTime) override;

		Rigidbody2D(float _mass, Vector2<float> _maxVelocity, Transform* _transform);
		Rigidbody2D();
		~Rigidbody2D();

	protected:
		void MoveLeft();
		void MoveRight();
		void AddGravity();
		void MoveUp();

	public:
		//added from last year AI 
		void applyForce(Vector2<float> force) { _force = force; };
		void clearForce() { _force = Vector2<float>::zero; };
		void AccumulateForce(Vector2<float> force) { _force += force; };

	};
}

