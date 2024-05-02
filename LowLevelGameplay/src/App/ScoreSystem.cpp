#include "Core/ScoreSystem.h"

LLGP::ScoreSystem::ScoreSystem()
{
	Player::LifeLost.AddListener(this, std::bind(&ScoreSystem::RespondToLifeLost, this, std::placeholders::_1));
	Player::DismountOtherPlayer.AddListener(this, std::bind(&ScoreSystem::RespondToDismountedPlayer, this, std::placeholders::_1));
	Enemy::BounderDismounted.AddListener(this, std::bind(&ScoreSystem::RespondToBounderDismount, this, std::placeholders::_1));
	Enemy::HunterDismounted.AddListener(this, std::bind(&ScoreSystem::RespondToHunterDismount, this, std::placeholders::_1));
	Enemy::ShadowLordDismounted.AddListener(this, std::bind(&ScoreSystem::RespondToShadowLordDismount, this, std::placeholders::_1));
	Enemy::EggPickedUp.AddListener(this, std::bind(&ScoreSystem::RespondToEggCaught, this, std::placeholders::_1));
	Enemy::PterodactylDefeated.AddListener(this, std::bind(&ScoreSystem::RespondToPterodactlyDefeated, this, std::placeholders::_1));
	
}
