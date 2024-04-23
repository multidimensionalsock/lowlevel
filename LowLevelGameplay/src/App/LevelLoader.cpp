#include "Core/LevelLoader.h"

LLGP::LevelLoader::LevelLoader(SceneManager* owner)
{
	rectPos = LLGP::Vector2<float>(0, 0);
	rectTex.loadFromFile("Textures/level .png");
	RectTexSize = LLGP::Vector2i(rectTex.getSize().x, rectTex.getSize().y);
	objectRenderer = sf::RectangleShape(RectTexSize);
	sceneManager = owner;

	sceneManager->Draw += std::bind(&LevelLoader::Draw, this, std::placeholders::_1);
}

void LLGP::LevelLoader::Draw(sf::RenderWindow& win)
{
	objectRenderer.setTexture(&rectTex);
	//objectRenderer.setTextureRect(rectTexUV);
	//objectRenderer.setOrigin(rectSize / 2);
	objectRenderer.setPosition(rectPos);
	sceneManager->window->draw(objectRenderer);
}
