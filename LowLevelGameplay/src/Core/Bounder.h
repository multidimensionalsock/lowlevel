#pragma once 
#include "Core/Enemy.h"

namespace LLGP
{
	class Player;

	class Bounder : public Enemy
	{
	public: 
		Bounder(SceneManager* manager, Player* playerRef) : Enemy(manager, playerRef) { Start(); };

	protected:
		void Start();
	};
}
