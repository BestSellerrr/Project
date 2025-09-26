#pragma once
#include "Enemy.h"

class CloneMaster :  public Enemy
{
public:

	//CloneMaster�� �ߵ��� ��ų ȿ�� �Լ�
	void Skill() override;

	//CloneMaster�� �ߵ��� ��ų�� ������ �� �Լ�
	void SkillOff() override;

	CloneMaster() = default;
	CloneMaster(std::string InName, float InHealth, float InPower, int InDropGold)
		:Enemy(InName, InHealth, InPower, InDropGold)
	{ }
};

