#include "CloneMaster.h"

void CloneMaster::Skill()
{
	printf("���� ���� ���� ����!!\n");
	SetPitchCount(PitchCount - 5);
}

void CloneMaster::SkillOff()
{
	SetPitchCount(PitchCount + 5);
}
