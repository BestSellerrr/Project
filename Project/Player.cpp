#include "Player.h"

#include <iostream>

void Player::PlayerArray()
{
	// ���� ġ�� ���� ������ ���� ���
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
