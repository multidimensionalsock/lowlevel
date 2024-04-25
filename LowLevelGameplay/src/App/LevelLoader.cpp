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
	GameObject* collider1 = new GameObject(sceneManager);
	collider1->SetTag("Floor");
	AABBCollider* col1 = collider1->AddComponent<AABBCollider>();
	col1->width = 65;
	col1->height = 16; 
	col1->position = Vector2<float>(0, 124);
	sceneManager->AddCollider(col1);
	
	//collider 2
	GameObject* collider2 = new GameObject(sceneManager);
	collider2->SetTag("Floor");
	AABBCollider* col2 = collider2->AddComponent<AABBCollider>();
	col2->width = 195;
	col2->height = 20;
	col2->position = Vector2<float>(176, 148);
	sceneManager->AddCollider(col2);

	//collider 3 

	//collider 4
	//collider 5
	//collider 6
	//collider 7
	//collider 8 
	//collider 9 (lava)
}


