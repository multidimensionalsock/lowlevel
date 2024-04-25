#pragma once
#include "Renderer.h"
#include "Core/ColliderTypes.h"
#include "Core/GameObject.h"

namespace LLGP 
{
	class LevelLoader : public GameObject
	{
		//this will make the level and add the colliders 
	public: 
		LevelLoader(SceneManager* owner) : GameObject(owner) 
		{
			rectPos = LLGP::Vector2<float>(0, 0);
			rectTex.loadFromFile("Textures/level .png");
			RectTexSize = LLGP::Vector2i(rectTex.getSize().x, rectTex.getSize().y);
			objectRenderer = sf::RectangleShape(RectTexSize);
			sceneManager = owner;
			AddColliders();

			sceneManager->Draw += std::bind(&LevelLoader::Draw, this, std::placeholders::_1);
		};

		LLGP::Vector2<float> rectPos;
		sf::Texture rectTex;
		//LLGP::Vector2i spritesInTex;
		LLGP::Vector2i RectTexSize;
		sf::RectangleShape objectRenderer;
		//SceneManager* sceneManager;

		void Draw(sf::RenderWindow& win);

	private:
		void AddColliders();

		
	};
}
