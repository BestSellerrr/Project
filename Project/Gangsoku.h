#pragma once
#include "Enemy.h"

class Gangsoku : public Enemy
{
public:

	//Gangsoku가 발동할 스킬 효과 함수
	void Skill() override;

	//Gangsoku가 발동한 스킬이 꺼졌을 때 함수
	void SkillOff() override;

	Gangsoku() = default;
	Gangsoku(std::string InName, float InHealth, float InPower, int InDropGold)
		:Enemy(InName, InHealth, InPower, InDropGold)
	{ }
};

