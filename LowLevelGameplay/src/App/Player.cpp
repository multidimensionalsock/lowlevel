#include "Core/Player.h"
#include "Core/Renderer.h"

void LLGP::Player::Start()
{
	//initialize and add components here 
	SetTag("Player");
	SetName("PlayerGameObject");
	AddComponent<Renderer>();
}
