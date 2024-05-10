#include "Core/EggLogic.h"
#include "Core/GameObject.h"
#include "Core/Bounder.h"

LLGP::EggLogic::~EggLogic()
{
	_GameObject->sceneManager->FixedUpdate.RemoveListener(this, std::bind(&EggLogic::FixedUpdate, this, std::placeholders::_1));
}

void LLGP::EggLogic::FixedUpdate(float fixedDeltaTime)
{
	framesActive++;

	if (framesActive > TimeBeforeSpawn * 50) 
	{
		SpawnEnemy();
	}
}

void LLGP::EggLogic::Start()
{
	_GameObject->sceneManager->FixedUpdate.AddListener(this, std::bind(&EggLogic::FixedUpdate, this, std::placeholders::_1));
}

void LLGP::EggLogic::SpawnEnemy()
{
	//create new bounder at location of egg
	Enemy* parentObj = static_cast<Enemy*>(_GameObject);
	Enemy* newEnemy = new Bounder(_GameObject->sceneManager, parentObj->_player);
	delete(_GameObject);
}
