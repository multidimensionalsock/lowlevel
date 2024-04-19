#include "Core/Renderer.h"
#include "Core/GameObject.h"

LLGP::Renderer::Renderer(GameObject* owner) 
{
	_GameObject = owner;
	owner->sceneManager->Update += std::bind(&Renderer::Update, this, std::placeholders::_1);
	owner->sceneManager->FixedUpdate += std::bind(&Renderer::FixedUpdate, this, std::placeholders::_1);
	owner->sceneManager->Draw += std::bind(&Renderer::Draw, this, std::placeholders::_1);

	rectSize = LLGP::Vector2<float>::one * 40;
	rectPos = LLGP::Vector2<float>(900, 450);
	rectTex.loadFromFile("Textures/sprite.png"); 
	//spritesInTex = LLGP::Vector2i(14, 9);
	RectTexSize = LLGP::Vector2i(rectTex.getSize().x, rectTex.getSize().y);
	//sf::IntRect rectTexUV(0, (RectTexSize.y / spritesInTex.y) * 5, RectTexSize.x / spritesInTex.x, RectTexSize.y / spritesInTex.y);
	objectRenderer = sf::RectangleShape(rectSize);
}

void LLGP::Renderer::Update(float deltaTime)
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	_GameObject->sceneManager->window->draw(shape);

}

void LLGP::Renderer::FixedUpdate(float fixedDeltaTime)
{
}

void LLGP::Renderer::Draw(sf::RenderWindow& win)
{
	objectRenderer.setTexture(&rectTex);
	//objectRenderer.setTextureRect(rectTexUV);
	//objectRenderer.setOrigin(rectSize / 2);
	objectRenderer.setPosition(_GameObject->transform.position);
	_GameObject->sceneManager->window->draw(objectRenderer);
}
