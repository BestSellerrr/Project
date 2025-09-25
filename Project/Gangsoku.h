#pragma once
#include "Enemy.h"
class Gangsoku : public Enemy
{
public:
	Gangsoku() = default;
	Gangsoku(std::string InName, float InHealth, float InPower, int InDropGold)
		:Enemy(InName, InHealth, InPower, InDropGold)
	{ }
};

