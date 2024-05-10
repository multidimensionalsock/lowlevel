#pragma once
#include "Core/Enemy.h"
namespace LLGP 
{
	class Egg : public Enemy
	{
	public:
		Egg(SceneManager* _sceneManager, Player* playerRef) : Enemy(_sceneManager, playerRef) { Start(); };
		~Egg();

		void Start();

	
	};
}
