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
	collider1->SetTag("Floor1");
	AABBCollider* col1 = collider1->AddComponent<AABBCollider>();
	col1->width = 65;
	col1->height = 16; 
	collider1->transform.position = Vector2<float>(0, 124);
	sceneManager->AddCollider(col1);
	
	//collider 2
	GameObject* collider2 = new GameObject(sceneManager);
	collider2->SetTag("Floor2");
	AABBCollider* col2 = collider2->AddComponent<AABBCollider>();
	col2->width = 195;
	col2->height = 20;
	collider2->transform.position = Vector2<float>(176, 148);
	sceneManager->AddCollider(col2);

	//collider 3 
	GameObject* collider3 = new GameObject(sceneManager);
	collider3->SetTag("Floor3");
	AABBCollider* col3 = collider3->AddComponent<AABBCollider>();
	col3->width = 102;
	col3->height = 15;
	collider3->transform.position = Vector2<float>(640 - 102, 123);
	sceneManager->AddCollider(col3);

	//collider 4
	GameObject* collider4 = new GameObject(sceneManager);
	collider4->SetTag("Floor4");
	AABBCollider* col4 = collider4->AddComponent<AABBCollider>();
	col4->width = 134;
	col4->height = 15;
	collider4->transform.position = Vector2<float>(0, 124 + 16 + 124);
	sceneManager->AddCollider(col4);

	//collider 5
	GameObject* collider5 = new GameObject(sceneManager);
	collider5->SetTag("Floor5");
	AABBCollider* col5 = collider5->AddComponent<AABBCollider>();
	col5->width = 144;
	col5->height = 12;
	collider5->transform.position = Vector2<float>(220, 310);
	sceneManager->AddCollider(col5);

	//collider 6
	GameObject* collider6 = new GameObject(sceneManager);
	collider6->SetTag("Floor6");
	AABBCollider* col6 = collider6->AddComponent<AABBCollider>();
	col6->width = 124;
	col6->height = 21;
	collider6->transform.position = Vector2<float>(429, 245);
	sceneManager->AddCollider(col6);

	//collider 7
	GameObject* collider7 = new GameObject(sceneManager);
	collider7->SetTag("Floor7");
	AABBCollider* col7 = collider7->AddComponent<AABBCollider>();
	col7->width = 92;
	col7->height = 16;
	collider7->transform.position = Vector2<float>(640 - 92, 123 + 15 + 123);
	sceneManager->AddCollider(col7);

	//collider 8 
	GameObject* collider8 = new GameObject(sceneManager);
	collider8->SetTag("Floor8");
	AABBCollider* col8 = collider8->AddComponent<AABBCollider>();
	col8->width = 473;
	col8->height = 7;
	collider8->transform.position = Vector2<float>(72, 124 + 16 + 124 + 16 + 130);
	sceneManager->AddCollider(col8);

	//collider 9 (lava)
	GameObject* collider9 = new GameObject(sceneManager);
	collider9->SetTag("Lava");
	AABBCollider* col9 = collider9->AddComponent<AABBCollider>();
	col9->width = 640;
	col9->height = 45;
	collider9->transform.position = Vector2<float>(0, 480 - 45);
	sceneManager->AddCollider(col9);
}


