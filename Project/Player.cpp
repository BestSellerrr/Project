#include "Player.h"

#include <iostream>

void Player::PlayerArray()
{
	// 공을 치기 위해 선택한 공간 출력
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

void Player::PlayerStatInfo()
{
	printf("체력: %.0f\n", GetPlayerHealth() * 100);
	printf("공격력: %.0f\n", GetPlayerPower() * 100);
	printf("배트 길이: %d\n", GetPlayerBatLength());

}

void Player::Hit(int* InX, int* InY, int* InBatLength)
{

	for (int i = 0; i < *InBatLength; i++)
	{
		int X = *InX + i;
		if (X > 4)
			X = 4;

		if (IsInStrikeZone(X, *InY))
		{
			Strike[*InY][X] = StrikeZoneCell::Strike;
		}
		else
		{
			Strike[*InY][X] = StrikeZoneCell::Ball;
		}
	}
}

void Player::Stand()
{

}
