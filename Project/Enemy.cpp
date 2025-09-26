#include "Enemy.h"
#include "Design.h"

#include <iostream>
#include <random>

void Enemy::EnemyArray()
{
	// ���� ���� ��ġ ���
	printf("[Enemy]\n");
	printf("����������������������������������������������������\n");
	for (int y = 0; y < StrikeZoneArray::ZoneSize; y++)
	{
		printf("��");
		for (int x = 0; x < StrikeZoneArray::ZoneSize; x++)
		{
			if (Strike[y][x] == StrikeZoneCell::Strike)
			{
				printf("  S ��");
			}
			else if (Strike[y][x] == StrikeZoneCell::Ball)
			{
				printf("  B ��");
			}
			else
			{
				printf("    ��");
			}
		}
		printf("\n");
		if (y != 4)
		{
			printf("����������������������������������������������������\n");
		}
	}
	printf("����������������������������������������������������\n");
}

void Enemy::EnemyStatInfo()
{
	printf("�̸�: %s\n", GetEnemyName().c_str());
	printf("ü��: %.0f\n", GetEnemyHealth() * 100);
	printf("���ݷ�: %.0f\n", GetEnemyPower() * 100);
	printf("��ų������: %.0f\n", GetEnemySkillGauge() * 100);
}

void Enemy::Throw(int InStartingBallCount)
{
	while (InStartingBallCount != 0)
	{
		int RandX = rand() % ZoneSize;
		int RandY = rand() % ZoneSize;
		if (!IsBallInZone(&RandX, &RandY))
		{
			if ((RandX > 0 && RandX < ZoneSize - 1)
			 && (RandY > 0 && RandY < ZoneSize - 1))
			{
				Strike[RandY][RandX] = StrikeZoneCell::Strike;
			}
			else
			{
				Strike[RandY][RandX] = StrikeZoneCell::Ball;
			}
		}		
		else
		{
			continue;
		}
		InStartingBallCount--;
	}
}

void Enemy::Skill()
{
	return;
}

void Enemy::SkillOff()
{
	return;
}

bool Enemy::IsEnemyMaxSkillGauge(Enemy* InEnemy)
{
	if (InEnemy->SkillGauge >= InEnemy->MaxSkillGauge)
	{
		return true;
	}
	return false;
}

void Enemy::EnemyPrintSkill(Enemy* InEnemy)
{

	if (IsEnemyMaxSkillGauge(InEnemy))
	{
		InEnemy->Skill();
		SetEnemySkillGauge(InEnemy->SkillGauge = 0.0f);
		SkillOnOff = true;
	}
	else if (!IsEnemyMaxSkillGauge(InEnemy) && (SkillOnOff == true))
	{
		InEnemy->SkillOff();
		SkillOnOff = false;
	}
	else
	{
		return;
	}
	return;
}
