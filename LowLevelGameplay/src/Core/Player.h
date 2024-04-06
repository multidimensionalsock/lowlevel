#pragma once
#include "Core/GameObject.h"

namespace LLGP
{
	class Player : public GameObject
	{
	public: 
		Player(SceneManager* manager) : GameObject(manager) { Start(); };

	protected: 
		void Start();

	};
}

