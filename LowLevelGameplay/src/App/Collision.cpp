#include "Core/Collision.h"
#include "Core/GameObject.h"
#include "Core/Renderer.h"
#include "Core/ColliderTypes.h"

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
	if (box1->position.x + (box1->width / 2) > box2->position.x &&
		box1->position.x + (box1->width / 2) < box2->position.x + box2->width &&
		box1->position.y + (box1->height / 2) > box2->position.y &&
		box1->position.y + (box1->height / 2) < box2->position.y + box2->height) 
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


