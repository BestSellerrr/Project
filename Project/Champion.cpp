#include "Champion.h"

void Champion::Skill()
{
	printf("�� �ϳ��� �º� ���ڴ�.\n");
	Power *= 2;
	SetPitchCount(PitchCount - 4);
}

void Champion::SkillOff()
{
	Power /= 2;
	SetPitchCount(PitchCount + 4);
}
