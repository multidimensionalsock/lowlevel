#include <SFML/Graphics.hpp>
#include "Core/Vector2.h"
#include <chrono>
#include "Core/MonoBehaviour.h"

#define FIXEDFRAMERATE 50

//namespace LLGP
//{
	int main()
	{
		float timeSincePhysicsStep = 0;

		sf::RenderWindow window(sf::VideoMode(1800, 900), "SFML Works!"); //original joust resolution

		MonoBehaviour* test = new MonoBehaviour();

		std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();
		float deltaTime = 0.f;

		while (window.isOpen())
		{
			std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
			deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - lastTime).count() / 1000000.f;
			lastTime = now;

			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			timeSincePhysicsStep += deltaTime;
			while (timeSincePhysicsStep > FIXEDFRAMERATE) 
			{
				//step the physics
				//collect collision info
				//dispatch collisions
				timeSincePhysicsStep -= FIXEDFRAMERATE;
			}

			window.clear();
			window.draw(test->objectRenderer);
			window.display();
		}

		return 0;
	}
//}
