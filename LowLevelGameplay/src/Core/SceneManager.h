#pragma once
#include "Core/Event.h"
#include "Core//GameObject.h"
#include <vector>

//used to call events for function in monobehaviour by the main function 
static class SceneManager : public GameObject
{ 
public:
	LLGP::Event<float> Update;
	LLGP::Event<float> FixedUpdate;
	LLGP::Event<> Draw;
	std::vector<GameObject*> gameObjectsWithColliders;


	void CallUpdate(float delta) { Update(delta); };
	void CallFixedUpdate(float delta) { FixedUpdate(delta); }
	void CallDraw() { Draw(); }

	void AddGameObjectToScene(GameObject* _gameobject);


	SceneManager();
	~SceneManager();

};

