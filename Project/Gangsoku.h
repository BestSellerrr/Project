#pragma once
#include "Enemy.h"

class Gangsoku : public Enemy
{
public:

	//Gangsoku�� �ߵ��� ��ų ȿ�� �Լ�
	void Skill() override;

	//Gangsoku�� �ߵ��� ��ų�� ������ �� �Լ�
	void SkillOff() override;

	Gangsoku() = default;
	Gangsoku(std::string InName, float InHealth, float InPower, int InDropGold)
		:Enemy(InName, InHealth, InPower, InDropGold)
	{ }
};

