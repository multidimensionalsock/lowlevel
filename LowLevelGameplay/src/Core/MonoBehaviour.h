#pragma once
#include "Core/Vector2.h"
#include <SFML/Graphics.hpp>

class MonoBehaviour
{
protected:
	LLGP::Vector2<float> position;
	LLGP::Vector2<float> rectSize;
	LLGP::Vector2<float> rectPos;
	sf::Texture rectTex;
	LLGP::Vector2i spritesInTex;
	LLGP::Vector2i rectTexSize;
	sf::IntRect rectTexUV;
	

public:
	MonoBehaviour(); //initialize
	~MonoBehaviour(); //deinitilize
	virtual void Start(); //called on creation 
	virtual void Update(float deltaTime); // called every frame
	virtual void FixedUpdate(float fixedDeltaTime); //called 50 times a second
	virtual void Draw(); //handles drawing to screen, once a frame
	virtual void initMesh();
	sf::RectangleShape objectRenderer;

};
