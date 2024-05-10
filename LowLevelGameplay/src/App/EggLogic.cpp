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

	if (framesActive > 120 * TimeBeforeSpawn) 
	{
		SpawnEnemy();
	}
}

//void LLGP::EggLogic::OnCollisionEnter(GameObject* other)
//{
//	if (other->GetTag() == "Player") 
//	{
//		Enemy* parent = static_cast<Enemy*>(_GameObject);
//		parent->broadCastEggPickup(grounded);
//		
//		//delete(_GameObject);
//	}
//	else if (other->GetTag() == "Floor")
//	{
//		grounded = true;
//	}
//	else if (other->GetTag() == "Lava")
//	{
//		delete(_GameObject);
//	}
//}

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
