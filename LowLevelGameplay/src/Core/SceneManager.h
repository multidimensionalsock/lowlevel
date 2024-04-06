#pragma once
#include "Core/Event.h"
#include "Core/Object.h"

//used to call events for function in monobehaviour by the main function 
class SceneManager : Object
{ 
public:
	LLGP::Event<float> Update;
	LLGP::Event<float> FixedUpdate;
	LLGP::Event<sf::RenderWindow&> Draw;
	sf::RenderWindow* window;

	void CallUpdate(float delta) { Update(delta); };
	void CallFixedUpdate(float delta) { FixedUpdate(delta); }
	void CallDraw(sf::RenderWindow& win) { Draw(win); }

	SceneManager();
	~SceneManager();

};

