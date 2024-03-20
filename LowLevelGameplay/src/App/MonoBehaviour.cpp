#include "Core/MonoBehaviour.h"

MonoBehaviour::MonoBehaviour()
{
	sf::Texture rectTex; rectTex.loadFromFile("Textures/joustsprites.jpg");
	//texture isnt loading but otherwise working? 
	initMesh(&rectTex, LLGP::Vector2i(rectTex.getSize().x, rectTex.getSize().y));
}

MonoBehaviour::~MonoBehaviour()
{
}

void MonoBehaviour::Start()
{

}

void MonoBehaviour::Update(float deltaTime)
{
}

void MonoBehaviour::FixedUpdate(float fixedDeltaTime)
{
}

void MonoBehaviour::Draw()
{
}

void MonoBehaviour::initMesh(sf::Texture* texture, LLGP::Vector2i rectTexSize)
{
	rectSize = LLGP::Vector2<float>::one * 100;
	rectPos = LLGP::Vector2<float>(900, 450);
	rectTex = texture;
	spritesInTex = LLGP::Vector2i(14, 9);
	RectTexSize = rectTexSize; 
	sf::IntRect rectTexUV(0, (rectTexSize.y / spritesInTex.y) * 5, rectTexSize.x / spritesInTex.x, rectTexSize.y / spritesInTex.y);
	objectRenderer = sf::RectangleShape(rectSize);
	objectRenderer.setTexture(rectTex);
	objectRenderer.setTextureRect(rectTexUV);
	objectRenderer.setOrigin(rectSize / 2);
	objectRenderer.setPosition(rectPos);
}

