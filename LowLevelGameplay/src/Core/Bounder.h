#pragma once 
#include "Core/Enemy.h"

namespace LLGP
{
	class Bounder : public Enemy
	{
	public: 
		Bounder(SceneManager* manager) : Enemy(manager) { Start(); };

	protected:
		void Start();
	};
}
