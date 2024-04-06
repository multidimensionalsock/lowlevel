#include "Core/SceneManager.h"
#include <iostream>
#include "Core/MonoBehaviour.h"
#include "Core/Renderer.h"
#include "Core/Player.h"

SceneManager::SceneManager()
{
	std::cout << "Scene Manager Created";
	LLGP::Player* testObj = new LLGP::Player(this);
}

SceneManager::~SceneManager()
{
	std::cout << "Scene Manager Destroyed";
}
