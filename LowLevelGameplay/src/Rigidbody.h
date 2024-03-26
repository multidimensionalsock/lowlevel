#pragma once
#include "Core/Vector2.h"

#define GRAVITY 0.260f

class Rigidbody
{
public: 
	LLGP::Vector2 velocity; 
	float mass;
	//froce down == mass x gravity

	//mass
	//gravtational force
protected:
	void AddGravity(float deltaTime);

};

