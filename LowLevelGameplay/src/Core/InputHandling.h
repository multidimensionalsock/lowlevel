#pragma once
#include "Core/Event.h"
#include <SFML/Graphics.hpp>

class InputHandling
{
public:
	LLGP::Event<bool> Left;
	LLGP::Event<bool> Right;
	LLGP::Event<bool> Up;

	void BroadcastLeft(bool arg) { Left(arg); }
	void BroadcastRight(bool arg) { Right(arg); }
	void BroadcastUp(bool arg) { Up(arg); }

	void PollInputs();

private:
	bool leftPressed = false;
	bool rightPressed = false;
	bool upPressed = false;
};

