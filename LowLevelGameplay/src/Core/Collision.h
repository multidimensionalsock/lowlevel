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


		static bool CircleCircleCollision(CircleCollider* circle1, CircleCollider* circle2);
		static bool AABBAABBCollision(AABBCollider* box1, AABBCollider* box2);
		static bool CircleAABBCollision(CircleCollider* circle, AABBCollider* box);
		static bool CircleAABBCollision(AABBCollider* box, CircleCollider* circle);


	private:

	};

	
};


