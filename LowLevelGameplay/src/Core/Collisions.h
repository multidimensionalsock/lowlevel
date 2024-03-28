#pragma once
#include "Core/Transform.h"
#include "Core//MonoBehaviour.h"
#include <vector>

enum CollisionType
{
	AABB,
	Circle
};

//only have of these, have it check against in check everyframe
namespace LLGP 
{
	//need to check what its colliding with so that it knows which math thing to do 
	//doesnt need to check against static objects (e.g. the platofrms never move its collider doesnt need to check
	class Collisions : public MonoBehaviour
	{
		// https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection
	public:
		bool checkEveryFrame;
		CollisionType type;
		//need to set who the gameobject is

		Collisions();
		~Collisions();
		void FixedUpdate(float fixedDeltaTime, std::vector<GameObject*> gameObjectsWithColliders);

	protected:
		bool CircleCircleCollision(CircleCollider circle1, CircleCollider circle2);
		bool AABBAABBCollision(AABBCollider aabb1, AABBCollider aabb2);
		bool CircleAABBCollision(CircleCollider circle1, AABBCollider aabb2);
		
	};

	class AABBCollider : public Collisions 
	{
	public:
		AABBCollider(bool check) { type = AABB; checkEveryFrame = check; };
		~AABBCollider();
		float _collisionExtent;
		float _width;
		float _height;

		void FixedUpdate(float fixedDeltaTime, Collisions collider1, Collisions collider2) override; //check against everything in the scene here ig??????????
	};

	class CircleCollider : public Collisions
	{
	public:
		CircleCollider(bool check) { type = Circle; checkEveryFrame = check; };
		~CircleCollider();

		float CollisionRadius;

		void FixedUpdate(float fixedDeltaTime) override; //check against everything in the scene here ig??????????

	};
}

