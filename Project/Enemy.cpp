#include "Enemy.h"

#include <iostream>
#include <random>

void Enemy::EnemyArray()
{
	// 던진 공의 위치 출력
	printf("┌────┬────┬────┬────┬────┐\n");
	for (int y = 0; y < StrikeZoneArray::ZoneSize; y++)
	{
		printf("│");
		for (int x = 0; x < StrikeZoneArray::ZoneSize; x++)
		{
			if (Strike[y][x] == StrikeZoneCell::Strike)
			{
				printf("  S │");
			}
			else if (Strike[y][x] == StrikeZoneCell::Ball)
			{
				printf("  B │");
			}
			else
			{
				printf("    │");
			}
		}
		printf("\n");
		if (y != 4)
		{
			printf("├────┼────┼────┼────┼────┤\n");
		}
	}
	printf("└────┴────┴────┴────┴────┘\n");
}

void Enemy::Throw(int InStartingBallCount)
{
	while (InStartingBallCount != 0)
	{
		int RandX = rand() % ZoneSize;
		int RandY = rand() % ZoneSize;
		if (IsBallInZone(&RandX, &RandY))
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
