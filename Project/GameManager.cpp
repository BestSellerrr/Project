#include "GameManager.h"
#include "Enemy.h"
#include "Player.h"
#include "StrikeZoneArray.h"
#include "Design.h"

#include"RookiePitcher.h"
#include "CloneMaster.h"
#include "Gangsoku.h"
#include "Champion.h"

#include <iostream>

void GameManager::Play()
{
	//������ ��ǥ�� 10 �������� ���� ��ų� �÷��̾��� ����� ���ϸ� ���� ����
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
	printf("[1]���� ���� / [2]���� / [3]�� ����\n");
	Jump(33);
	printf("�Է�: ");
}

void GameManager::InputMenu()
{
	int Input = 0;
	std::cin >> Input;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	Enemy* NewEnemy = RandomEnemy();
	Enemy* LastEnemy = AppearChampion();
	UpdateStatsFromStage(NewEnemy, &enemy.Stage);

	switch (Input)
	{
	case 1:		
		Jump(26);
		//10 �������� ������ ������ �� ����
		if (enemy.Stage != enemy.MaxStage)
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
	case 3:
		player.PlayerStatInfo();
		Line();
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
		Line();
		InEnemy.EnemyStatInfo();
		Line();
		player.PlayerStatInfo();

		InEnemy.EnemyPrintSkill(&InEnemy);
		player.PlayerPrintUlt();

		//�Ź� �ٸ� ���� �������� �迭 ����X
		printf("���� ���� ������\n\n");		
		InEnemy.Throw(InEnemy.PitchCount);

		printf("ĥ ���� �Է�(0 ~ 4): ");
		std::cin >> InputX >> InputY;

		//������ ����ų� ���ڰ� �ƴ� ���ڿ� �Է� �� while�� ó������ �̵�
		if ((std::cin.fail()) || (!(strikezonearray.IsInPitchZone(InputX, InputY))))
		{
			Jump(26);
			printf("�߸� �Է� �ϼ˽��ϴ�\n");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			InEnemy.ArrayReset();
			continue;
		}

		player.Hit(&InputX, &InputY, &player.BatLength);
		player.PlayerArray();
		InEnemy.EnemyArray();

		if (IsPlayerHit(player, InEnemy))
		{
			Line();
			printf("�ƽ��ϴ�!!\n");
			InEnemy.Health -= player.Power;
			InEnemy.SetEnemySkillGauge(InEnemy.SkillGauge + 0.2f);
			player.MoveUpBase();
		}
		else
		{
			Line();
			printf("���ƽ��ϴ�...\n");
			player.Health -= InEnemy.Power;
		}
		InEnemy.ArrayReset();
		player.ArrayReset();

		if (InEnemy.Health < 0.01f)
		{
			Jump(2);
			printf("�̰���ϴ�!!\n");
			player.Gold += InEnemy.DropGold;

			//�� óġ�� ���̵� ������ ���� �������� �� + 1
			enemy.SetStage(enemy.Stage + 1);
			Line();			
			break;
		}
		else if (player.Health < 0.01f)
		{
			Jump(1);
			printf("�÷��̾ �׾����ϴ�\n");
			player.Life--;
			Line();
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
			player.Gold -= 100;
			break;
		case 2:
			if (player.Gold < PowerPrice)
			{
				printf("��尡 �����մϴ�\n");
				break;
			}
			printf("���ݷ� + 10\n");
			player.Power += 0.1f;
			player.Gold -= 100;
			break;
		case 3:
			if (player.Gold < BatLengthPrice)
			{
				printf("��尡 �����մϴ�\n");
				break;
			}
			printf("��Ʈ ���� + 1\n");
			player.BatLength += 1;
			player.Gold -= 1000;
			break;
		case 9:
			break;
		default:
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			else
			{
				continue;
			}
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
	Enemy* LastEnemy = new Champion("è�Ǿ�", 10.0f, 2.5f, 100000000);
	return LastEnemy;
}

void GameManager::UpdateStatsFromStage(Enemy* InEnemy, int* InStage)
{
	InEnemy->Stage = *InStage;
	InEnemy->Health += (*InStage * 0.5f);
	InEnemy->Power += (*InStage * 0.1f);
	InEnemy->DropGold += (*InStage * 100);
	InEnemy->PitchCount -= *InStage;
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
