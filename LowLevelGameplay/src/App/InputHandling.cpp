#include "Core/InputHandling.h"

void InputHandling::PollInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) 
	{
		if (leftPressed != true) 
		{
			leftPressed = true;
			BroadcastLeft(true);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) 
	{
		if (rightPressed != true) 
		{
			rightPressed = true;
			BroadcastRight(true);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) 
	{
		if (upPressed == false) {
			upPressed = true;
			BroadcastUp(true); 
		}
	}
}
