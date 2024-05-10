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
		void broadCastBounderDismouted(UUID* other) { BounderDismounted(other); }
		inline static Event<UUID*> HunterDismounted;
		void broadCastBounderDismounted(UUID* other) { HunterDismounted(other); }
		inline static Event<UUID*> ShadowLordDismounted;
		void broadCastShadowLordDismount(UUID* other) { ShadowLordDismounted(other); }
		inline static Event<bool> EggPickedUp; //bool is whether it happened mid air
		void broadCastEggPickup(bool inAir) { EggPickedUp(inAir); }
		inline static Event<UUID*> PterodactylDefeated;
		void broadCastPterodactylDefeated(UUID* other) { PterodactylDefeated(other); }

		
	};
}

