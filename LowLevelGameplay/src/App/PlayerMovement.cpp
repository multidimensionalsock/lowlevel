#include "Core/PlayerMovement.h"

LLGP::PlayerMovement::PlayerMovement(GameObject* owner)
{
	_GameObject = owner; 


	/*owner->sceneManager->Update += std::bind(&Renderer::Update, this, std::placeholders::_1);
	owner->sceneManager->FixedUpdate += std::bind(&Renderer::FixedUpdate, this, std::placeholders::_1);
	owner->sceneManager->Draw += std::bind(&Renderer::Draw, this, std::placeholders::_1);*/
}

void LLGP::PlayerMovement::Update(float deltaTime)
{
}

void LLGP::PlayerMovement::FixedUpdate(float fixedDeltaTime)
{
}
