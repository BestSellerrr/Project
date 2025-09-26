#include "Champion.h"

void Champion::Skill()
{
	printf("공 하나로 승부 보겠다.\n");
	Power *= 2;
	SetPitchCount(PitchCount - 4);
}

void Champion::SkillOff()
{
	Power /= 2;
	SetPitchCount(PitchCount + 4);
}
