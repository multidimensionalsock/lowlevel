#pragma once
#include "Core/Vector2.h"
#include <SFML/Graphics.hpp>
#include "Core/SceneManager.h"
#include "Core/Object.h"



namespace LLGP 
{
	class GameObject;

	class MonoBehaviour : public Object
	{
	public:



	protected:
		

		GameObject* _GameObject;


	public:
		MonoBehaviour() {};
		MonoBehaviour(GameObject* owner) : _GameObject(owner) {} //initialize
		//MonoBehaviour(GameObject* owner, SceneManager* manager);
		virtual ~MonoBehaviour() {}; //deinitilize

		GameObject* GetGameObject() { return _GameObject; }

		virtual void OwnerActiveChange(bool newActive) {}

		//these will get called by the parent gameobject not scene manager now 
		virtual void Update(float deltaTime); // called every frame
		virtual void FixedUpdate(float fixedDeltaTime); //called 50 times a second
		virtual void Draw(sf::RenderWindow& win); //handles drawing to screen, once a frame
		virtual void initMesh(sf::Texture* texture, LLGP::Vector2i rectTexSize);
		

	};
}
