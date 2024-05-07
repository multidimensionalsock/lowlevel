#include "Core/Collision.h"
#include "Core/GameObject.h"
#include "Core/Renderer.h"
#include "Core/ColliderTypes.h"

bool LLGP::Collision::CircleCircleCollision(CircleCollider* circle1, CircleCollider* circle2)
{
	Vector2<float> vec = Vector2<float>((circle1->position.x - circle2->position.x),
		(circle1->position.y - circle2->position.y));
	float distance = sqrt((vec.x * vec.x) + (vec.y * vec.y));
	float distanceToCollide = (circle1->radius + circle2->radius);
	return distance < distanceToCollide;
}


bool LLGP::Collision::AABBAABBCollision(AABBCollider* box1, AABBCollider* box2)
{
	LLGP::Vector2<float> box1Pos = box1->GetGameObject()->transform.position;
	LLGP::Vector2<float> box2Pos = box2->GetGameObject()->transform.position;
	if (box1Pos.x < box2Pos.x + box2->width &&
		box1Pos.x + box1->width > box2Pos.x &&
		box1Pos.y < box2Pos.y + box2->height &&
		box1Pos.y + box1->height > box2Pos.y) // top
	{
		return true;
	}
	return false;
}


bool LLGP::Collision::CircleAABBCollision(CircleCollider* circle, AABBCollider* box)
{
	//circle side 
	Vector2<float> vec = Vector2<float>((box->position.x - circle->position.x),
		(box->position.y - circle->position.y));
	float distance = sqrt((vec.x * vec.x) + (vec.y * vec.y));
	float distanceToCollideX = (circle->radius + box->width);
	float distanceToCollideY = (circle->radius + box->height);

	if (distance < distanceToCollideX || distance < distanceToCollideY)
		return true;
	
	//circle corner 
	//pythadoras for AABB radius and then add radius of circle to find distance
	//and compare 
	float AABBradius = sqrt((box->height * box->height) + (box->width * box->width));
	float distanceToCollide = circle->radius + AABBradius;
	return distance < distanceToCollide;
}

bool LLGP::Collision::CircleAABBCollision(AABBCollider* box, CircleCollider* circle)
{
	return CircleAABBCollision(circle, box);
}


