#include "GameManager.h"
#include "Enemy.h"
#include "Player.h"
#include "StrikeZoneArray.h"
#include "Base.h"

#include"RookiePitcher.h"
#include "CloneMaster.h"
#include "Gangsoku.h"
#include "Champion.h"

#include <iostream>

void GameManager::Play()
{
	while (true)
	{
		PrintMenu();
		InputMenu();		

		if (IsPlayerDie(player))
			break;
	}
	PrintResult();
}

void GameManager::PrintMenu()
{
	printf("���� �������� : %d\n",enemy.Stage);
	printf("���� ��� : %d\n",player.Life);
	printf("[1]���� ���� / [2]����\n");
}

void GameManager::InputMenu()
{
	int Input = 0;
	std::cin >> Input;
	Enemy* NewEnemy = RandomEnemy();
	Enemy* LastEnemy = AppearChampion();
	UpdateStatsFromStage(NewEnemy, &NewEnemy->Stage);

	switch (Input)
	{
	case 1:		
		if (NewEnemy->Stage != NewEnemy->MaxStage)
			Game(*NewEnemy);
		else
			Game(*LastEnemy);
		delete LastEnemy;
		delete NewEnemy;
		LastEnemy = nullptr;
		NewEnemy = nullptr;
		break;
	case 2:
		Shop();
		break;
	default:
		break;
	}
}

void GameManager::Game(Enemy& InEnemy)
{
	int InputX = 0;
	int InputY = 0;

	printf("���� ��Ÿ����!!\n");

	while (true)
	{		
		InEnemy.EnemyStatInfo();

		player.PlayerStatInfo();

		InEnemy.Throw(InEnemy.CanThrowBall);
		printf("���� ���� ������\n");

		printf("ĥ ���� �Է�(0 ~ 4): ");
		std::cin >> InputX >> InputY;
		if (!(strikezonearray.IsInPitchZone(InputX, InputY)))
		{
			printf("�ٽ� �Է��ϼ���\n");
			continue;
		}

		player.Hit(&InputX, &InputY, &player.BatLength);
		player.PlayerArray();
		InEnemy.EnemyArray();

		if (IsPlayerHit(player, InEnemy))
		{
			printf("�ƽ��ϴ�!!\n");
			InEnemy.Health -= player.Power;
		}
		else
		{
			printf("���ƽ��ϴ�...\n");
			player.Health -= InEnemy.Power;
		}
		InEnemy.ArrayReset();
		player.ArrayReset();

		if (InEnemy.Health < 0.01f)
		{
			printf("�̰���ϴ�!!");
			player.Gold += InEnemy.DropGold;
			enemy.SetStage(enemy.Stage + 1);
			break;
		}
		else if (player.Health < 0.01f)
		{
			printf("�÷��̾ �׾����ϴ�");
			break;
		}
	}
}

void GameManager::Shop()
{
	int Input = 0;
	while (!(Input == 9))
	{
		printf("[���׷��̵�]\n");
		printf("[1]ü��(100��) / [2]���ݷ�(100) / [3]��Ʈ ����(1000) / [9]������\n");
		printf("���� ���� ��� : %d\n", player.Gold);
		std::cin >> Input;

		switch (Input)
		{
		case 1:
			if (player.Gold < HealthPrice)
			{
				printf("��尡 �����մϴ�\n");
				break;
			}
			printf("ü�� + 100\n");
			player.Health += 1.0f;
			break;
		case 2:
			if (player.Gold < PowerPrice)
			{
				printf("��尡 �����մϴ�\n");
				break;
			}
			printf("���ݷ� + 10\n");
			player.Power += 0.1f;
			break;
		case 3:
			if (player.Gold < BatLengthPrice)
			{
				printf("��尡 �����մϴ�\n");
				break;
			}
			printf("��Ʈ ���� + 1\n");
			player.BatLength += 1;
			break;
		case 9:
			break;
		default:
			break;
		}
	}
}

Enemy* GameManager::RandomEnemy()
{
	Enemy* NewEnemy = nullptr;
	int RandomEnemy = rand() % 3;

	switch (RandomEnemy)	
	{
	case 0:
		NewEnemy = new RookiePitcher("��Ű", 1.0f, 0.1f, 200);
		break;
	case 1:
		NewEnemy = new CloneMaster("Ŭ�� ������", 1.2f, 0.15f, 300);
		break;
	case 2:
		NewEnemy = new Gangsoku("���ӱ�", 1.1f, 0.2f, 350);
		break;
	default:
		break;
	}
	return NewEnemy;
}

Enemy* GameManager::AppearChampion()
{
	Enemy* LastEnemy = new Champion("è�Ǿ�", 8.0f, 2.5f, 100000000);
	return LastEnemy;
}

void GameManager::UpdateStatsFromStage(Enemy* InEnemy, int* InStage)
{
	InEnemy->Health += *InStage * 0.5f;
	InEnemy->Power += *InStage * 0.1f;
	InEnemy->DropGold += *InStage * 100;
	InEnemy->CanThrowBall -= *InStage;
}

void GameManager::PrintResult()
{
	if (IsPlayerDie(player))
	{
		printf("�׾����ϴ�\n");
	}
	else
	{
		printf("�¸�!");
	}
}
