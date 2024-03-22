#include "Core/SceneManager.h"
#include <iostream>
#include "Core/MonoBehaviour.h"

SceneManager::SceneManager()
{
	std::cout << "Scene Manager Created";
	MonoBehaviour* test = new MonoBehaviour(this);
}

SceneManager::~SceneManager()
{
	std::cout << "Scene Manager Destroyed";
}
