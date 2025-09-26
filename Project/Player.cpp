#include "Player.h"
#include "Design.h"

#include <iostream>

void Player::PlayerArray()
{
	// 공을 치기 위해 선택한 공간 출력
	printf("[Player]\n");
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
	printf("체력: \t\t%.0f\n", GetPlayerHealth() * 100);
	printf("공격력: \t%.0f\n", GetPlayerPower() * 100);
	printf("배트 길이: \t%d\n", GetPlayerBatLength());
	printf("궁극기 게이지: \t%d\n", GetPlayerUltGauge());
	printf("궁극기 개수: \t%d\n", GetPlayerUltNumber());
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
		printf("1루타!\n");
		UltGauge += 25;
	}
	else if (RandomMove < 85)
	{
		printf("2루타!!\n");
		UltGauge += 50;
	}
	else if (RandomMove < 95)
	{
		printf("3루타!!!\n");
		UltGauge += 75;
	}
	else
	{
		printf("홈런!!!!\n");
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
		printf("궁극기 사용하시겠습니까?\n");
		printf("Yes[1] / No[2]\n");
		std::cin >> Input;
		if (Input == 1)
		{
			printf("궁극기를 사용하셧습니다\n");
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
