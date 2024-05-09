#include "Core/SceneManager.h"
#include <iostream>
#include "Core/MonoBehaviour.h"
#include "Core/Renderer.h"
#include "Core/Player.h"
#include "Core/ColliderTypes.h"
#include "Core/Textures.h"
#include "Core/LevelLoader.h"
#include "Core/ScoreSystem.h"
#include "Core/Bounder.h"

LLGP::SceneManager::SceneManager()
{
	std::cout << "Scene Manager Created";
	scoreSystem = new ScoreSystem();
	textureLoad = Textures();
	LLGP::Player* player = new LLGP::Player(this);
	
	LevelLoader* level = new LevelLoader(this);
	Bounder* testEnemy = new Bounder(this,player );
	
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
			if (i == j) { continue; }
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
