#include "Core/Collision.h"
#include "Core/GameObject.h"
#include "Core/Renderer.h"

LLGP::AABBCollider::AABBCollider(GameObject* owner)
{
	_GameObject = owner;
	//need width and height 
	Renderer* _renderer = _GameObject->GetComponent<Renderer>();
	width = _renderer->rectSize.x;
	height = _renderer->rectSize.y;
	position = _GameObject->transform.position;
	if (!moveable) return;
	owner->sceneManager->Update += std::bind(&AABBCollider::Update, this, std::placeholders::_1);
}

void LLGP::AABBCollider::Update(float deltaTime)
{
	position = _GameObject->transform.position; 
}

LLGP::CircleCollider::CircleCollider(GameObject* owner) 
{
	_GameObject = owner;
	//need radius 
	Renderer* _renderer = _GameObject->GetComponent<Renderer>();
	radius = _renderer->rectSize.x / 2;
	position = _GameObject->transform.position;
	if (!moveable) return;
	owner->sceneManager->Update += std::bind(&CircleCollider::Update, this, std::placeholders::_1);
}
