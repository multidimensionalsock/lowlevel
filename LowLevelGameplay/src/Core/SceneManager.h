#pragma once
#include "Core/Event.h"

//used to call events for function in monobehaviour by the main function 
class SceneManager
{ 
public:
	LLGP::Event<> Update;
	LLGP::Event<> FixedUpdate;
	LLGP::Event<> Draw;

	void CallUpdate() { Update(); };
	void CallFixedUpdate() { FixedUpdate(); }
	void CallDraw() { Draw(); }

	SceneManager();
	~SceneManager();

};

