#pragma once
#include "Core/GameObject.h"

namespace LLGP
{
	class Player : public GameObject
	{
	public: 
		Player(SceneManager* manager) : GameObject(manager) { Start(); };

		inline static Event<UUID*> LifeLost;
		inline static Event<UUID*> DismountOtherPlayer;

	protected: 
		void Start();

	};

}
