#pragma once
#include "Core/Collision.h"


namespace LLGP
{
	class AABBCollider : public Collision
	{
	public:
		AABBCollider(GameObject* owner);


		float width;
		float height;

		/*void SetMovement(bool val) 
		{
			moveable = val; 
			if (moveable)
				_GameObject->sceneManager->Update += std::bind(&AABBCollider::Update, this, std::placeholders::_1);

		}*/


	};

	class CircleCollider : public Collision
	{
	public:
		CircleCollider(GameObject* owner);
		float radius;

	};
}
