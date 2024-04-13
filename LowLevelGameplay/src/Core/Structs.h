#pragma once
#include "Core/Vector2.h"

struct Transform
{
	LLGP::Vector2<float> position = LLGP::Vector2<float>::zero;
	LLGP::Vector2<float> rotation = LLGP::Vector2<float>::zero;
	LLGP::Vector2<float> scale = LLGP::Vector2<float>::one;
};
