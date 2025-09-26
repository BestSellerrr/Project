#pragma once
#include "Enemy.h"

class RookiePitcher : public Enemy
{
public:
	
	//RookiePitcher가 발동할 스킬 효과 함수
	void Skill() override;

	//RookiePitcher가 스킬이 꺼졌을 때 함수
	void SkillOff() override;

	RookiePitcher() = default;
	RookiePitcher(std::string InName, float InHealth, float InPower, int InDropGold)
		:Enemy(InName, InHealth, InPower, InDropGold)
	{ }
};

