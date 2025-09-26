#pragma once
#include "Enemy.h"

class Champion : public Enemy
{
public:

	//Champion이 발동할 스킬 효과 함수
	void Skill() override;

	//Champion이 발동한 스킬이 껴졌을 때 함수
	void SkillOff() override;

	Champion() = default;
	Champion(std::string InName, float InHealth, float InPower, int InDropGold)
		:Enemy(InName,InHealth,InPower,InDropGold)
	{ }
};

