#include <SFML/Graphics.hpp>
#include "Core/Vector2.h"

//namespace LLGP
//{
	int main()
	{
		sf::RenderWindow window(sf::VideoMode(1800, 900), "SFML Works!"); //original joust resolution

		LLGP::Vector2<float> rectSize = LLGP::Vector2<float>::one * 100;
		LLGP::Vector2<float> rectPos = LLGP::Vector2<float>(900, 450);
		sf::RectangleShape shape(rectSize);
		shape.setFillColor(sf::Color::Blue);
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
