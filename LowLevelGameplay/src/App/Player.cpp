#include "Core/Player.h"
#include "Core/Renderer.h"
#include "Core/RigidBody2D.h"

void LLGP::Player::Start()
{
	//initialize and add components here 
	SetTag("Player");
	SetName("PlayerGameObject");
	AddComponent<Renderer>();
	RigidBody2D* rb = AddComponent<LLGP::RigidBody2D>();
	rb->SetMass(0.1f);
	rb->SetTransform(&transform);

}
