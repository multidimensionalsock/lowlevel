#include "Core/MonoBehaviour.h"
using namespace LLGP;

MonoBehaviour::MonoBehaviour(GameObject* owner, SceneManager* manager)
{
	/*manager->Update += std::bind(&MonoBehaviour::Update, this, std::placeholders::_1);
	manager->FixedUpdate += std::bind(&MonoBehaviour::FixedUpdate, this, std::placeholders::_1);*/
}

void MonoBehaviour::Update(float deltaTime)
{
	std::cout << "1";
}

void MonoBehaviour::FixedUpdate(float fixedDeltaTime)
{
	std::cout << "2";
}

void MonoBehaviour::Draw()
{
}

void MonoBehaviour::initMesh(sf::Texture* texture, LLGP::Vector2i rectTexSize)
{
	
}

