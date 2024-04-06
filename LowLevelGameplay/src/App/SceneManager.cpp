#include "Core/SceneManager.h"
#include <iostream>
#include "Core/MonoBehaviour.h"
#include "Core/GameObject.h"
#include "Core/Renderer.h"

SceneManager::SceneManager()
{
	std::cout << "Scene Manager Created";
	GameObject* testObj = new GameObject(this);
	//LLGP::Renderer* renderer = new LLGP::Renderer(testObj, this);
	//LLGP::MonoBehaviour* test = new LLGP::MonoBehaviour(testObj);
	//testObj->AddComponent<LLGP::Renderer>(testObj, this);
}

SceneManager::~SceneManager()
{
	std::cout << "Scene Manager Destroyed";
}
