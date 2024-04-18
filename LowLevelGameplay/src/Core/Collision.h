#pragma once 
#include "Core/MonoBehaviour.h"

enum CollisionType 
{
	Circle,
	AABB
};

namespace LLGP
{
	

	class CircleCollider;
	class AABBCollider;

	class Collision : public MonoBehaviour
	{
	public:
		CollisionType type;

		bool CircleCircleCollision(CircleCollider* circle1, CircleCollider* circle2);
		bool AABBAABBCollision(AABBCollider* box1, AABBCollider* box2);
		bool CircleAABBCollision(CircleCollider* circle, AABBCollider* box);
		bool CircleAABBCollision(AABBCollider* box, CircleCollider* circle);

	private:

	};

	
};


