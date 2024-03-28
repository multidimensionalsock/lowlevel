#include "Core/SceneManager.h"
#include <iostream>
#include "Core/MonoBehaviour.h"
#include <Core/Collisions.h>

void SceneManager::AddColliderToScene(LLGP::Collisions* _gameobject)
{
	gameObjectsWithColliders.push_back(_gameobject); 
}

SceneManager::SceneManager()
{
	std::cout << "Scene Manager Created";
	//MonoBehaviour* test = new MonoBehaviour(this);
}

SceneManager::~SceneManager()
{
	std::cout << "Scene Manager Destroyed";
}
