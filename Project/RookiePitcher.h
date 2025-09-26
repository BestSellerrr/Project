#pragma once
#include "Enemy.h"

class RookiePitcher : public Enemy
{
public:
	
	//RookiePitcher�� �ߵ��� ��ų ȿ�� �Լ�
	void Skill() override;

	//RookiePitcher�� ��ų�� ������ �� �Լ�
	void SkillOff() override;

	RookiePitcher() = default;
	RookiePitcher(std::string InName, float InHealth, float InPower, int InDropGold)
		:Enemy(InName, InHealth, InPower, InDropGold)
	{ }
};

