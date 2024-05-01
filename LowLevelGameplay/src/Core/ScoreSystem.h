#pragma once
#include "Core/Event.h"
#include "Core/Enemy.h"
#include "Core/Player.h"
#include <vector>

namespace LLGP 
{
	class ScoreSystem 
	{
	public:
		ScoreSystem();

		Event<int> scoreIncrease; //pass through new score value
		Event<UUID*> playerLifeLost;

	private:
		int EggsCaught = 0;
		int score;

		void RespondToBounderDismount(UUID* enemy) { score += 500; scoreIncrease(score); }
		void RespondToHunterDismount(UUID* enemy) { score += 750; scoreIncrease(score); } //750
		void RespondToShadowLordDismount(UUID* enemy) { score += 1500; scoreIncrease(score); } //1500
		void RespondToEggCaught(bool midair)
		{
			EggsCaught++;
			switch (EggsCaught)
			{
			case 1:
				score += 250;
				break;
			case 2:
				score += 500;
				break;
			case 3:
				score += 750;
				break;
			default:
				score += 1000;
				break;
			};
			if (midair) score += 500;
			scoreIncrease(score);
		}
		//250, 500, 750, 1000, 500 extra is bool true
		void RespondToPterodactlyDefeated(UUID* enemy) { score += 1000; scoreIncrease(score); } //1000
		void RespondToLifeLost(UUID* player) { score += 50; scoreIncrease(score); }; //50
		void RespondToDismountedPlayer(UUID* player) { score += 1000; scoreIncrease(score); } //1000
	};

}
