#pragma once
#include "Core/MonoBehaviour.h"

namespace LLGP
{
	class Renderer : MonoBehaviour
	{
	public: 
		//Renderer();
		Renderer(GameObject* owner, SceneManager* manager);

		void Update(float deltaTime) override; // called every frame
		void FixedUpdate(float fixedDeltaTime) override;

		

	protected: 
		LLGP::Vector2<float> position;
		LLGP::Vector2<float> rectSize;
		LLGP::Vector2<float> rectPos;
		sf::Texture* rectTex;
		LLGP::Vector2i spritesInTex;
		LLGP::Vector2i RectTexSize;
		sf::IntRect rectTexUV;
		sf::RectangleShape objectRenderer;

		

	};
}

