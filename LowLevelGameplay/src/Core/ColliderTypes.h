#pragma once
#include "Core/Collision.h"


namespace LLGP
{
	class AABBCollider : public Collision
	{
	public:
		AABBCollider(GameObject* owner);

		bool moveable;

		float width;
		float height;
		Vector2<float> position;

		/*void SetMovement(bool val) 
		{
			moveable = val; 
			if (moveable)
				_GameObject->sceneManager->Update += std::bind(&AABBCollider::Update, this, std::placeholders::_1);

		}*/

		void Update(float deltaTime) override;

	};

	class CircleCollider : public Collision
	{
	public:
		CircleCollider(GameObject* owner);
		bool moveable;
		float radius;
		Vector2<float> position;

		void Update(float deltaTime) override;
	};
}
