#include <SFML/Graphics.hpp>
#include "Core/Vector2.h"

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



		while (window.isOpen())
		{
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
