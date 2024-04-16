#pragma once
#include "Core/MonoBehaviour.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

namespace LLGP
{
	class Renderer : public MonoBehaviour
	{
	public: 
		//Renderer();
		Renderer(GameObject* owner);

		void Update(float deltaTime) override; // called every frame
		void FixedUpdate(float fixedDeltaTime) override;
		void Draw(sf::RenderWindow& win) override;

		LLGP::Vector2<float> rectSize;

		

	protected: 
		LLGP::Vector2<float> position;
		
		LLGP::Vector2<float> rectPos;
		sf::Texture rectTex;
		LLGP::Vector2i spritesInTex;
		LLGP::Vector2i RectTexSize;
		sf::IntRect rectTexUV;
		sf::RectangleShape objectRenderer;

		

	};
}

