#include "CloneMaster.h"

void CloneMaster::Skill()
{
	printf("던진 공의 개수 감소!!\n");
	SetPitchCount(PitchCount - 5);
}

void CloneMaster::SkillOff()
{
	SetPitchCount(PitchCount + 5);
}
