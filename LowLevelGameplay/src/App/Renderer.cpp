#include "Core/Renderer.h"

LLGP::Renderer::Renderer(GameObject* owner, SceneManager* manager)
{
	_GameObject = owner;
	manager->Update += std::bind(&Renderer::Update, this, std::placeholders::_1);
	manager->FixedUpdate += std::bind(&Renderer::FixedUpdate, this, std::placeholders::_1);

	rectSize = LLGP::Vector2<float>::one * 100;
	rectPos = LLGP::Vector2<float>(900, 450);
	rectTex->loadFromFile("Textures/joustsprites.jpg");
	spritesInTex = LLGP::Vector2i(14, 9);
	RectTexSize = LLGP::Vector2i(rectTex->getSize().x, rectTex->getSize().y);
	sf::IntRect rectTexUV(0, (RectTexSize.y / spritesInTex.y) * 5, RectTexSize.x / spritesInTex.x, RectTexSize.y / spritesInTex.y);
	objectRenderer = sf::RectangleShape(rectSize);
	objectRenderer.setTexture(rectTex);
	objectRenderer.setTextureRect(rectTexUV);
	objectRenderer.setOrigin(rectSize / 2);
	objectRenderer.setPosition(rectPos);
}

void LLGP::Renderer::Update(float deltaTime)
{
}

void LLGP::Renderer::FixedUpdate(float fixedDeltaTime)
{
}
