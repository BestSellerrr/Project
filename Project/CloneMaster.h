#pragma once
#include "Enemy.h"

class CloneMaster :  public Enemy
{
public:

	//CloneMaster가 발동할 스킬 효과 함수
	void Skill() override;

	//CloneMaster가 발동한 스킬이 꺼졌을 때 함수
	void SkillOff() override;

	CloneMaster() = default;
	CloneMaster(std::string InName, float InHealth, float InPower, int InDropGold)
		:Enemy(InName, InHealth, InPower, InDropGold)
	{ }
};

