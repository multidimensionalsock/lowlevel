#pragma once
#include "Core/GameObject.h"
#include "Core/Event.h"

namespace LLGP
{
	class Enemy : public GameObject
	{
	public: 
		inline static Event<UUID*> BounderDismounted;
		inline static Event<UUID*> HunterDismounted;
		inline static Event<UUID*> ShadowLordDismounted;
		inline static Event<bool> EggPickedUp; //bool is whether it happened mid air
		inline static Event<UUID*> PterodactylDefeated;
	};
}

