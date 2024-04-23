#include "Core/Renderer.h"
#include "Core/GameObject.h"
#include "Core/Textures.h"

LLGP::Renderer::Renderer(GameObject* owner) 
{
	_GameObject = owner;
	owner->sceneManager->Update += std::bind(&Renderer::Update, this, std::placeholders::_1);
	owner->sceneManager->FixedUpdate += std::bind(&Renderer::FixedUpdate, this, std::placeholders::_1);
	owner->sceneManager->Draw += std::bind(&Renderer::Draw, this, std::placeholders::_1);

	
	rectPos = LLGP::Vector2<float>(900, 450);
	TextureDetails renderDetails = owner->sceneManager->textureLoad.sparkle;
	rectTex = renderDetails.texture; 
	spritesInTex = renderDetails.spritesInTexture;
	RectTexSize = renderDetails.RectTexSize;
	rectTexUV = renderDetails.rectTexUV;
	rectSize = LLGP::Vector2<float>::one * 40;
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
	objectRenderer.setTextureRect(rectTexUV);
	//objectRenderer.setOrigin(rectSize / 2);
	objectRenderer.setPosition(_GameObject->transform.position);
	_GameObject->sceneManager->window->draw(objectRenderer);
}
