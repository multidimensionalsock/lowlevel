#include "Core/MonoBehaviour.h"
using namespace LLGP;

void MonoBehaviour::Update(float deltaTime)
{
	std::cout << "1";
}

void MonoBehaviour::FixedUpdate(float fixedDeltaTime)
{
	std::cout << "2";
}

void MonoBehaviour::Draw(sf::RenderWindow& win)
{
}

void MonoBehaviour::initMesh(sf::Texture* texture, LLGP::Vector2i rectTexSize)
{
	
}

