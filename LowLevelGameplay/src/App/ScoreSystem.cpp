#include "Core/ScoreSystem.h"

LLGP::ScoreSystem::ScoreSystem()
{
	Player::LifeLost += std::bind(&ScoreSystem::RespondToLifeLost, this, std::placeholders::_1);
	Player::DismountOtherPlayer += std::bind(&ScoreSystem::RespondToDismountedPlayer, this, std::placeholders::_1);
	Enemy::BounderDismounted += std::bind(&ScoreSystem::RespondToBounderDismount, this, std::placeholders::_1);
	Enemy::HunterDismounted += std::bind(&ScoreSystem::RespondToHunterDismount, this, std::placeholders::_1);
	Enemy::ShadowLordDismounted += std::bind(&ScoreSystem::RespondToShadowLordDismount, this, std::placeholders::_1);
	Enemy::EggPickedUp += std::bind(&ScoreSystem::RespondToEggCaught, this, std::placeholders::_1);
	Enemy::PterodactylDefeated += std::bind(&ScoreSystem::RespondToPterodactlyDefeated, this, std::placeholders::_1);
	
}
