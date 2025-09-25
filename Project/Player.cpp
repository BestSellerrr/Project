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

void Player::PlayerStatInfo()
{
	printf("ü��: %.0f\n", GetPlayerHealth() * 100);
	printf("���ݷ�: %.0f\n", GetPlayerPower() * 100);
	printf("��Ʈ ����: %d\n", GetPlayerBatLength());

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
