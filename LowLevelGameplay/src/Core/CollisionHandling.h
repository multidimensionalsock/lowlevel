#pragma once
#include "Core/MonoBehaviour.h"
#include "Core/Transform.h"

class CollisionHandling
{
};

enum CollisionType
{
	Circle,
	AABB
};

namespace LLGP
{
	class Collider : public MonoBehaviour 
	{
	public: 
		CollisionType _type;
		Transform* _transform;
		GameObject* _gameObject;

		Collider();
		~Collider();
	};

	class CircleCollider : public Collider
	{
	public:
		float _radius; 

		CircleCollider(Transform* transform, GameObject* gameObject, float radius)
		{
			_transform = transform;
			_gameObject = gameObject;
			_type = Circle;
			_radius = radius;

		};
	};

	class AABBCollider : public Collider
	{
		public: 
		float width;
		float height;

		AABBCollider(Transform* transform, GameObject* gameObject, float w, float h)
		{
			_transform = transform;
			_gameObject = gameObject;
			width = w;
			height = h;
		};

	};
}

