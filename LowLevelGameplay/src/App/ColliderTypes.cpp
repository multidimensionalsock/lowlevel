#include "Core/ColliderTypes.h"
#include "Core/GameObject.h"
#include "Core/Renderer.h"


LLGP::CircleCollider::CircleCollider(GameObject* owner)
{
	_GameObject = owner;
	type = Circle;
	//need radius 
	Renderer* _renderer = _GameObject->GetComponent<Renderer>();
	if (_renderer != nullptr)
	{
		radius = _renderer->rectSize.x / 2;
	}
}


LLGP::AABBCollider::AABBCollider(GameObject* owner)
{
	_GameObject = owner;
	type = AABB;
	//need width and height 
	Renderer* _renderer = _GameObject->GetComponent<Renderer>();
	if (_renderer != nullptr) {
		width = _renderer->rectSize.x;
		height = _renderer->rectSize.y;
	}
	//owner->sceneManager->Update.AddListener(this, std::bind(&AABBCollider::Update, this, std::placeholders::_1));
}
