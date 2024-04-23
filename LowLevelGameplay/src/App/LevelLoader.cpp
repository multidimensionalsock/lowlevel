#include "Core/LevelLoader.h"



void LLGP::LevelLoader::Draw(sf::RenderWindow& win)
{
	objectRenderer.setTexture(&rectTex);
	//objectRenderer.setTextureRect(rectTexUV);
	//objectRenderer.setOrigin(rectSize / 2);
	objectRenderer.setPosition(rectPos);
	sceneManager->window->draw(objectRenderer);
}

void LLGP::LevelLoader::AddColliders()
{
	//collider 1
	AABBCollider* collider1 = AddComponent<AABBCollider>();
	collider1->width = 65;
	collider1->height = 16; 
	collider1->position = Vector2<float>(124, 0);
	sceneManager->AddCollider(collider1);

	//collider 2
	//collider 3 
	//collider 4
	//collider 5
	//collider 6
	//collider 7
	//collider 8 
	//collider 9 (lava)
}


