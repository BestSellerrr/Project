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
