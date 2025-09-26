#include "Gangsoku.h"

void Gangsoku::Skill()
{
	printf("공격력 1.5배!!!\n");
	Power *= 1.5;
}

void Gangsoku::SkillOff()
{
	Power /= 1.5;
}
	