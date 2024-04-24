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

//```cpp
//bool AABBColliderComponent::Intersects(const std::shared_ptr<AABBColliderComponent>& collider)
//{
//	Bounds thisBounds = GetBounds();
//	Bounds colliderBounds = collider->GetBounds();
//	return (thisBounds.Min.X <= colliderBounds.Max.X && thisBounds.Max.X >= colliderBounds.Min.X) &&
//		(thisBounds.Min.Y <= colliderBounds.Max.Y && thisBounds.Max.Y >= colliderBounds.Min.Y) &&
//		(thisBounds.Min.Z <= colliderBounds.Max.Z && thisBounds.Max.Z >= colliderBounds.Min.Z);
//}
//```

//if (rect1.x + (rect1.width / 2) > rect2.x &&
//	rect1.x + (rect1.width / 2) < rect2.x + rect2.width &&
//	rect1.y + (rect1.height / 2) > rect2.y &&
//	rect1.y + (rect1.height / 2) < rect2.y + rect2.height) {
//	return true;
//}

bool LLGP::Collision::AABBAABBCollision(AABBCollider* box1, AABBCollider* box2)
{
	if (box1->position.x < box2->position.x + box2->width &&
		box1->position.x + box1->width > box2->position.x &&
		box1->position.y < box2->position.y + box2->height &&
		box1->position.y + box1->height > box2->position.y) // top
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


