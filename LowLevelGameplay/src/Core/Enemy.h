#pragma once
#include "Core/GameObject.h"
#include "Core/Event.h"

namespace LLGP
{
	class Player; 

	class Enemy : public GameObject
	{
	public: 
		Enemy() = default;
		Enemy(SceneManager* manager, Player* player) : GameObject(manager) { _player = player; }

		Player* _player;

		inline static Event<UUID*> BounderDismounted;
		inline static Event<UUID*> HunterDismounted;
		inline static Event<UUID*> ShadowLordDismounted;
		inline static Event<bool> EggPickedUp; //bool is whether it happened mid air
		inline static Event<UUID*> PterodactylDefeated;

		
	};
}

