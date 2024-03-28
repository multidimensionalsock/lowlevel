#include "Core/SceneManager.h"
#include <iostream>
#include "Core/MonoBehaviour.h"

SceneManager::SceneManager()
{
	std::cout << "Scene Manager Created";
	//LLGP::MonoBehaviour* test = new LLGP::MonoBehaviour();
}

SceneManager::~SceneManager()
{
	std::cout << "Scene Manager Destroyed";
}
