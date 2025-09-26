#include "Player.h"
#include "Design.h"

#include <iostream>

void Player::PlayerArray()
{
	// ���� ġ�� ���� ������ ���� ���
	printf("[Player]\n");
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
	printf("ü��: \t\t%.0f\n", GetPlayerHealth() * 100);
	printf("���ݷ�: \t%.0f\n", GetPlayerPower() * 100);
	printf("��Ʈ ����: \t%d\n", GetPlayerBatLength());
	printf("�ñر� ������: \t%d\n", GetPlayerUltGauge());
	printf("�ñر� ����: \t%d\n", GetPlayerUltNumber());
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

void Player::UseUlt()
{
	UltNumber--;
	Power *= 1.5;
}

void Player::ResetUlt()
{
	Power /= 1.5;
}

void Player::MoveUpBase()
{
	int RandomMove = rand() % 10;
	if (RandomMove < 55)
	{
		printf("1��Ÿ!\n");
		UltGauge += 25;
	}
	else if (RandomMove < 85)
	{
		printf("2��Ÿ!!\n");
		UltGauge += 50;
	}
	else if (RandomMove < 95)
	{
		printf("3��Ÿ!!!\n");
		UltGauge += 75;
	}
	else
	{
		printf("Ȩ��!!!!\n");
		UltGauge += 100;
	}

	if (UltGauge >= 100)
	{
		UltGauge -= 100;
		UltNumber++;
	}
}

bool Player::IsPlayerMaxUltGauge()
{
	if (UltNumber > 0)
	{
		return true;
	}
	return false;
}

void Player::PlayerPrintUlt()
{
	int Input = 0;
	if (IsPlayerMaxUltGauge())
	{
		printf("�ñر� ����Ͻðڽ��ϱ�?\n");
		printf("Yes[1] / No[2]\n");
		std::cin >> Input;
		if (Input == 1)
		{
			printf("�ñر⸦ ����ϼ˽��ϴ�\n");
			UseUlt();
			UltOnOff = true;
		}
		else
		{
			return;
		}
	}
	else if (!IsPlayerMaxUltGauge() && (UltOnOff == true))
	{
		ResetUlt();
		UltOnOff = false;
	}
	else
	{
		return;
	}
	return;
}
