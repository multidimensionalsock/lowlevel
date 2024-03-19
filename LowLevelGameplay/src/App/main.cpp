#include <SFML/Graphics.hpp>
#include <Core/Vector2.h>

namespace LLGP
{
	int main()
	{
		sf::RenderWindow window(sf::VideoMode(292, 240), "SFML Works!"); //original joust resolution
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);

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
}
