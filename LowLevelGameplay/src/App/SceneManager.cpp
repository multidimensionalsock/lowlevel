#include "Core/SceneManager.h"
#include <iostream>
#include "Core/MonoBehaviour.h"
#include "Core/GameObject.h"

SceneManager::SceneManager()
{
	std::cout << "Scene Manager Created";
	GameObject* testObj = new GameObject("test", "test");
	LLGP::MonoBehaviour* test = new LLGP::MonoBehaviour(this);
	testObj->AddComponent(test);
}

SceneManager::~SceneManager()
{
	std::cout << "Scene Manager Destroyed";
}
