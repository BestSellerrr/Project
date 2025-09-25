#pragma once
#include "Enemy.h"
class Champion : public Enemy
{
public:

	void ChampionSkill();

	Champion() = default;
	Champion(std::string InName, float InHealth, float InPower, int InDropGold)
		:Enemy(InName,InHealth,InPower,InDropGold)
	{ }
};

