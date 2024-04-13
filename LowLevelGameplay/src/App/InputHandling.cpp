#include "Core/InputHandling.h"

void LLGP::InputHandling::PollInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) 
	{
		if (leftPressed != true) 
		{
			leftPressed = true;
			BroadcastLeft(true);
		}
	}
	else 
	{
		leftPressed = false;
		BroadcastLeft(false);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) 
	{
		std::cout << "d pressed" << std::endl;
		if (rightPressed != true) 
		{
			rightPressed = true;
			BroadcastRight(true);
		}
	}
	else 
	{
		rightPressed = false;
		BroadcastRight(false);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) 
	{

		if (upPressed == false) {
			upPressed = true;
			BroadcastUp(true); 
		}
	}
	else 
	{
		if (upPressed = true) 
		{
			upPressed = false;
			BroadcastUp(false);
		}
	}
}
