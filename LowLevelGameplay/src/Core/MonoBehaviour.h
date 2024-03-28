#pragma once
#include "Core/Vector2.h"
#include <SFML/Graphics.hpp>
#include "Core/SceneManager.h"
#include "Core/Object.h"

class GameObject;

namespace LLGP 
{
	class MonoBehaviour : public Object
	{
	public:



	protected:
		//move these into a renderer
		LLGP::Vector2<float> position;
		LLGP::Vector2<float> rectSize;
		LLGP::Vector2<float> rectPos;
		sf::Texture* rectTex;
		LLGP::Vector2i spritesInTex;
		LLGP::Vector2i RectTexSize;
		sf::IntRect rectTexUV;

		GameObject* _GameObject;


	public:
		MonoBehaviour();
		MonoBehaviour(GameObject* owner) : _GameObject(owner) {} //initialize
		MonoBehaviour(GameObject* owner, SceneManager* manager);
		virtual ~MonoBehaviour() {}; //deinitilize

		GameObject* GetGameObject() { return _GameObject; }

		virtual void OwnerActiveChange(bool newActive) {}

		//these will get called by the parent gameobject not scene manager now 
		virtual void Update(float deltaTime); // called every frame
		virtual void FixedUpdate(float fixedDeltaTime); //called 50 times a second
		virtual void Draw(); //handles drawing to screen, once a frame
		virtual void initMesh(sf::Texture* texture, LLGP::Vector2i rectTexSize);
		sf::RectangleShape objectRenderer;

	};
}
