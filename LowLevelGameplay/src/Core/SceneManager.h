#pragma once
#include "Core/Event.h"
#include "Core/Object.h"
#include <vector>
#include "Core/Textures.h"

namespace LLGP
{
	class Collision;
	class ScoreSystem;

	//used to call events for function in monobehaviour by the main function 
	class SceneManager : Object
	{
	public:
		LLGP::Event<float> Update;
		LLGP::Event<float> FixedUpdate;
		LLGP::Event<sf::RenderWindow&> Draw;
		sf::RenderWindow* window;
		Textures textureLoad;

		void CallUpdate(float delta) { Update(delta); };
		void CallFixedUpdate(float delta) { FixedUpdate(delta); }
		void CallDraw(sf::RenderWindow& win) { Draw(win); }

		SceneManager();
		~SceneManager();

		void AddCollider(LLGP::Collision* collider);
		void RemoveCollider(LLGP::Collision* collider);
		void CheckCollisions();

	private:
		std::vector<LLGP::Collision*> _SceneColliders;
		ScoreSystem* scoreSystem;

	};
}

