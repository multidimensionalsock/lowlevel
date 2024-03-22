#include <SFML/Graphics.hpp>
#include "Core/Vector2.h"
#include <chrono>
#include "Core/MonoBehaviour.h"
#include "Core/InputHandling.h"
#include "Core/SceneManager.h"

#define FIXEDFRAMERATE 0.00005f //50 fps

//namespace LLGP
//{
	int main()
	{
		float timeSincePhysicsStep = 0;

		sf::RenderWindow window(sf::VideoMode(1800, 900), "SFML Works!"); //original joust resolution

		//create objects here
		//MonoBehaviour* test = new MonoBehaviour(this);
		InputHandling* input = new InputHandling(); //tracks inputs
		SceneManager* sceneManager = new SceneManager();
		

		std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();
		float deltaTime = 0.f;

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
			deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - lastTime).count() / 1000000.f;
			
			lastTime = now;

			//fixed update not calling 50 times a second
			timeSincePhysicsStep += deltaTime;
			while (timeSincePhysicsStep > FIXEDFRAMERATE) 
			{
				std::cout << "fixed";
				//run fixed update on components 
				//need to work out a fixed delta to use here
				sceneManager->CallFixedUpdate(deltaTime);
				//step the physics
				//collect collision info
				//dispatch collisions
				timeSincePhysicsStep -= FIXEDFRAMERATE;
			}

			//poll for inputs for mono behaviour to use 
			input->PollInputs();
			sceneManager->CallUpdate(deltaTime);
			
			

			window.clear();
			sceneManager->CallDraw();
			//window.draw(test->objectRenderer);
			window.display();
		}

		return 0;
	}


