#pragma once 
#include "Core/MonoBehaviour.h"

namespace LLGP
{

	class Collision : public MonoBehaviour
	{
	public:
		bool CircleCircleCollision();
		bool AABBAABBCollision();
		bool CircleAABBCollision();

	private:

	};

	class AABBCollider : public Collision
	{
	public:
		AABBCollider(GameObject* owner);

		bool moveable;

		float width;
		float height;
		Vector2<float> position;

		void Update(float deltaTime) override;
			
	};

	class CircleCollider : public Collision
	{
		CircleCollider(GameObject* owner);
		bool moveable;
		float radius;
		Vector2<float> position;
	};
};

//bool Collisions::Circle(Character* character1, Character* character2) {
//	Vector2D vec = Vector2D((character1->GetPosition().x - character2->GetPosition().x),
//		(character1->GetPosition().y - character2->GetPosition().y));
//	double distance = sqrt((vec.x * vec.x) + (vec.y * vec.y));
//	double combined_distance = (character1->GetCollisionRadius() + character2->GetCollisionRadius());
//	return distance < combined_distance;
//
//}
//bool Collisions::Box(Rect2D rect1, Rect2D rect2) {
//	if (rect1.x + (rect1.width / 2) > rect2.x &&
//		rect1.x + (rect1.width / 2) < rect2.x + rect2.width &&
//		rect1.y + (rect1.height / 2) > rect2.y &&
//		rect1.y + (rect1.height / 2) < rect2.y + rect2.height) {
//		return true;
//	}
//	return false;
//}
