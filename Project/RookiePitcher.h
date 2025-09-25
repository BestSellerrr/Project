#pragma once
#include "Enemy.h"
class RookiePitcher : public Enemy
{
public:
	RookiePitcher() = default;
	RookiePitcher(std::string InName, float InHealth, float InPower, int InDropGold)
		:Enemy(InName, InHealth, InPower, InDropGold)
	{ }
};

