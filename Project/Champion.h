#pragma once
#include "Enemy.h"

class Champion : public Enemy
{
public:

	//Champion�� �ߵ��� ��ų ȿ�� �Լ�
	void Skill() override;

	//Champion�� �ߵ��� ��ų�� ������ �� �Լ�
	void SkillOff() override;

	Champion() = default;
	Champion(std::string InName, float InHealth, float InPower, int InDropGold)
		:Enemy(InName,InHealth,InPower,InDropGold)
	{ }
};

