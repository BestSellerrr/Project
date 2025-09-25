#pragma once
#include "Enemy.h"
class CloneMaster :  public Enemy
{
public:



public:
	CloneMaster() = default;
	CloneMaster(std::string InName, float InHealth, float InPower, int InDropGold)
		:Enemy(InName, InHealth, InPower, InDropGold)
	{ }
};

