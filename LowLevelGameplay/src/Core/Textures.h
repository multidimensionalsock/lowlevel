#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "Core/Vector2.h"

struct TextureDetails 
{
	sf::Texture texture;
	LLGP::Vector2i spritesInTexture;
	LLGP::Vector2i RectTexSize;
	sf::IntRect rectTexUV;
};

namespace LLGP 
{
	class Textures
	{
	public:
		TextureDetails enemyBird;
		TextureDetails fire;
		TextureDetails lavaTroll;
		TextureDetails humans;
		TextureDetails player1Bird;
		TextureDetails player2Bird;
		TextureDetails pterdactyl;
		TextureDetails sparkle;

		Textures()
		{
			enemyBird = loadTextureDetails("Textures/enemybirds 1.png", LLGP::Vector2i(1, 14));
			//fire = loadTextureDetails("Textures/fire 1.png");
		}

	private:

		TextureDetails loadTextureDetails(std::string path, LLGP::Vector2i spritesInTexture)
		{
			TextureDetails details;
			details.texture.loadFromFile(path);
			details.spritesInTexture = spritesInTexture;
			details.RectTexSize = LLGP::Vector2i(details.texture.getSize().x, details.texture.getSize().y);
			details.rectTexUV = sf::IntRect(0, (details.RectTexSize.y / details.spritesInTexture.y) * 5, details.RectTexSize.x /
				details.spritesInTexture.x, details.RectTexSize.y / details.spritesInTexture.y);
			return details;
		}
	};
}

//rectTex.loadFromFile("Textures/sprite.png");
////spritesInTex = LLGP::Vector2i(14, 9);
//RectTexSize = LLGP::Vector2i(rectTex.getSize().x, rectTex.getSize().y);
////sf::IntRect rectTexUV(0, (RectTexSize.y / spritesInTex.y) * 5, RectTexSize.x / spritesInTex.x, RectTexSize.y / spritesInTex.y);
//objectRenderer = sf::RectangleShape(rectSize);

//LLGP::Vector2<float> rectPos;
//sf::Texture rectTex;
//LLGP::Vector2i spritesInTex;
//LLGP::Vector2i RectTexSize;
//sf::IntRect rectTexUV;
//sf::RectangleShape objectRenderer;
