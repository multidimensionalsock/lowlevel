#pragma once
#include "Renderer.h"

namespace LLGP 
{
	class LevelLoader : MonoBehaviour
	{
		//this will make the level and add the colliders 
	public: 
		LevelLoader(SceneManager* owner);

		LLGP::Vector2<float> rectPos;
		sf::Texture rectTex;
		LLGP::Vector2i spritesInTex;
		LLGP::Vector2i RectTexSize;
		sf::RectangleShape objectRenderer;
		SceneManager* sceneManager;

		void Draw(sf::RenderWindow& win) override;
		
	};
}
