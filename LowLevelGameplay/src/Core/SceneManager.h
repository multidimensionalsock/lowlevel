#pragma once
#include "Core/Event.h"

//used to call events for function in monobehaviour by the main function 
class SceneManager : Object
{ 
public:
	LLGP::Event<float> Update;
	LLGP::Event<float> FixedUpdate;
	LLGP::Event<> Draw;

	void CallUpdate(float delta) { Update(delta); };
	void CallFixedUpdate(float delta) { FixedUpdate(delta); }
	void CallDraw() { Draw(); }

	SceneManager();
	~SceneManager();

};

