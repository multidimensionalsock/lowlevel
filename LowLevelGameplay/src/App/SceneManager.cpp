#include "Core/SceneManager.h"
#include <iostream>
#include "Core/MonoBehaviour.h"
#include "Core/Renderer.h"
#include "Core/Player.h"
#include "Core/ColliderTypes.h"

LLGP::SceneManager::SceneManager()
{
	std::cout << "Scene Manager Created";
	LLGP::Player* testObj = new LLGP::Player(this);
}

LLGP::SceneManager::~SceneManager()
{
	std::cout << "Scene Manager Destroyed";
}

void LLGP::SceneManager::AddCollider(LLGP::Collision* collider)
{
	_SceneColliders.push_back(collider);
}

void LLGP::SceneManager::RemoveCollider(LLGP::Collision* collider)
{
	for (int i = 0; i < _SceneColliders.size(); i++)
	{
		if (_SceneColliders[i]->uuid == collider->uuid)
			_SceneColliders.erase(std::next(_SceneColliders.begin(), i));
	}
}

void LLGP::SceneManager::CheckCollisions()
{
	//go throught the collider list and check if theyre colliding 
	//tell the object the collisions status 
	bool col = false;
	for (int i = 0; i < _SceneColliders.size(); i++)
	{
		
		for (int j = 0; j < _SceneColliders.size(); j++)
		{
			col = false;
			if (_SceneColliders[i]->type == _SceneColliders[j]->type)
			{
				if (_SceneColliders[i]->type == AABB)
				{
					col = _SceneColliders[i]->AABBAABBCollision(static_cast<AABBCollider*>(_SceneColliders[i]), static_cast<AABBCollider*>(_SceneColliders[j]));
				}
				else
				{
					col = _SceneColliders[i]->CircleCircleCollision(static_cast<CircleCollider*>(_SceneColliders[i]), static_cast<CircleCollider*>(_SceneColliders[j]));
				}
			}
			else 
			{
				if (_SceneColliders[i]->type == AABB)
				{
					col = _SceneColliders[i]->CircleAABBCollision(static_cast<CircleCollider*>(_SceneColliders[j]), static_cast<AABBCollider*>(_SceneColliders[i]));
				}
				else
				{
					col = _SceneColliders[i]->CircleAABBCollision(static_cast<CircleCollider*>(_SceneColliders[i]), static_cast<AABBCollider*>(_SceneColliders[j]));
				}
			}
			_SceneColliders[i]->GetGameObject()->Colliding(col, _SceneColliders[j]->GetGameObject());
		}
	}
}
