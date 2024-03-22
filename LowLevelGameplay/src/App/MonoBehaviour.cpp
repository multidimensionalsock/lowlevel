#include "Core/MonoBehaviour.h"

MonoBehaviour::MonoBehaviour(SceneManager* manager)
{
	sf::Texture rectTex; rectTex.loadFromFile("Textures/joustsprites.jpg");
	//texture isnt loading but otherwise working? 
	initMesh(&rectTex, LLGP::Vector2i(rectTex.getSize().x, rectTex.getSize().y));

	manager->Update += std::bind(&MonoBehaviour::Update, this, std::placeholders::_1);
	manager->FixedUpdate += std::bind(&MonoBehaviour::FixedUpdate, this, std::placeholders::_1);
	//manager->Draw += std::bind(&MonoBehaviour::Draw, this, std::placeholders::_1);

	//add listeners to scene manager functions to the below 
}

MonoBehaviour::~MonoBehaviour()
{
}


void MonoBehaviour::Update(float deltaTime)
{
	//std::cout << "Update called";
}

void MonoBehaviour::FixedUpdate(float fixedDeltaTime)
{
	//std::cout << "Fixed Update called";
}

void MonoBehaviour::Draw()
{
}

void MonoBehaviour::initMesh(sf::Texture* texture, LLGP::Vector2i rectTexSize)
{
	rectSize = LLGP::Vector2<float>::one * 100;
	rectPos = LLGP::Vector2<float>(900, 450);
	rectTex = texture;
	spritesInTex = LLGP::Vector2i(14, 9);
	RectTexSize = rectTexSize; 
	sf::IntRect rectTexUV(0, (rectTexSize.y / spritesInTex.y) * 5, rectTexSize.x / spritesInTex.x, rectTexSize.y / spritesInTex.y);
	objectRenderer = sf::RectangleShape(rectSize);
	objectRenderer.setTexture(rectTex);
	objectRenderer.setTextureRect(rectTexUV);
	objectRenderer.setOrigin(rectSize / 2);
	objectRenderer.setPosition(rectPos);
}

