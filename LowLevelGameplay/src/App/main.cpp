#include <SFML/Graphics.hpp>
#include "Core/Vector2.h"
#include <chrono>

//namespace LLGP
//{
	int main()
	{
		sf::RenderWindow window(sf::VideoMode(1800, 900), "SFML Works!"); //original joust resolution

		LLGP::Vector2<float> rectSize = LLGP::Vector2<float>::one * 100;
		LLGP::Vector2<float> rectPos = LLGP::Vector2<float>(900, 450);
		sf::Texture rectTex; rectTex.loadFromFile("Textures/joustsprites.jpg");
		LLGP::Vector2i spritesInTex(14, 9);
		LLGP::Vector2i rectTexSize(rectTex.getSize().x, rectTex.getSize().y);
		sf::IntRect rectTexUV(0, (rectTexSize.y / spritesInTex.y) * 5, rectTexSize.x / spritesInTex.x, rectTexSize.y / spritesInTex.y);
		sf::RectangleShape shape(rectSize);
		shape.setTexture(&rectTex);
		shape.setTextureRect(rectTexUV);
		shape.setOrigin(rectSize / 2);
		shape.setPosition(rectPos);

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

			window.clear();
			window.draw(shape);
			window.display();
		}

		return 0;
	}
//}
