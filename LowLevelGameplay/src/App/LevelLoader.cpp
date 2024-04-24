#include "Core/LevelLoader.h"



void LLGP::LevelLoader::Draw(sf::RenderWindow& win)
{
	objectRenderer.setTexture(&rectTex);
	//objectRenderer.setTextureRect(rectTexUV);
	//objectRenderer.setOrigin(rectSize / 2);
	objectRenderer.setPosition(rectPos);
	sceneManager->window->draw(objectRenderer);

	LLGP::Vector2<float> rectSize1 = LLGP::Vector2<float>(65, 16);
	LLGP::Vector2<float> rectPos1 = LLGP::Vector2<float>(900, 450);
	sf::RectangleShape shape(rectSize1);
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(rectPos1);
	sceneManager->window->draw(shape);
}

void LLGP::LevelLoader::AddColliders()
{
	//collider 1
	AABBCollider* collider1 = AddComponent<AABBCollider>();
	collider1->width = 65;
	collider1->height = 16; 
	collider1->position = Vector2<float>(0, 124);
	sceneManager->AddCollider(collider1);
	//Renderer* ren = AddComponent<Renderer>();
	

	//collider 2
	//collider 3 
	//collider 4
	//collider 5
	//collider 6
	//collider 7
	//collider 8 
	//collider 9 (lava)
}


