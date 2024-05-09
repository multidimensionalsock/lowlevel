#pragma once
#include "Core/MonoBehaviour.h"

namespace LLGP 
{
	class EggLogic : public MonoBehaviour
	{
	public:
		EggLogic(GameObject* owner) : MonoBehaviour(owner) { Start(); }
		~EggLogic() {};

		void FixedUpdate(float fixedDeltaTime) override;

	private:
		float TimeBeforeSpawn = 10.f; //how many second the egg will exist before hatching 
		int framesActive = 0; //how mnay frames the egg has existed for

		void Start();

		void SpawnEnemy();
	};
}

