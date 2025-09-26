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
	//게임의 목표인 10 스테이지 보스 잡거나 플레이어의 목숨이 다하면 게임 종료
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
	printf("현재 스테이지 : %d\n",enemy.Stage);
	printf("남은 목숨 : %d\n",player.Life);
	printf("[1]전투 시작 / [2]상점 / [3]내 정보\n");
	Jump(33);
	printf("입력: ");
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
		//10 스테이지 전까지 랜덤한 적 출현
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

	printf("적이 나타났다!!\n");

	while (true)
	{		
		Line();
		InEnemy.EnemyStatInfo();
		Line();
		player.PlayerStatInfo();

		InEnemy.EnemyPrintSkill(&InEnemy);
		player.PlayerPrintUlt();

		//매번 다른 공을 던지도록 배열 고정X
		printf("상대는 공을 던졌다\n\n");		
		InEnemy.Throw(InEnemy.PitchCount);

		printf("칠 공간 입력(0 ~ 4): ");
		std::cin >> InputX >> InputY;

		//범위를 벗어나거나 숫자가 아닌 문자열 입력 시 while문 처음으로 이동
		if ((std::cin.fail()) || (!(strikezonearray.IsInPitchZone(InputX, InputY))))
		{
			Jump(26);
			printf("잘못 입력 하셧습니다\n");
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
			printf("쳤습니다!!\n");
			InEnemy.Health -= player.Power;
			InEnemy.SetEnemySkillGauge(InEnemy.SkillGauge + 0.2f);
			player.MoveUpBase();
		}
		else
		{
			Line();
			printf("못쳤습니다...\n");
			player.Health -= InEnemy.Power;
		}
		InEnemy.ArrayReset();
		player.ArrayReset();

		if (InEnemy.Health < 0.01f)
		{
			Jump(2);
			printf("이겼습니다!!\n");
			player.Gold += InEnemy.DropGold;

			//적 처치후 난이도 증가를 위한 스테이지 수 + 1
			enemy.SetStage(enemy.Stage + 1);
			Line();			
			break;
		}
		else if (player.Health < 0.01f)
		{
			Jump(1);
			printf("플레이어가 죽었습니다\n");
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
		printf("[업그레이드]\n");
		printf("[1]체력(100원) / [2]공격력(100) / [3]배트 길이(1000) / [9]나가기\n");
		printf("현재 보유 골드 : %d\n", player.Gold);
		std::cin >> Input;

		

		switch (Input)
		{
		case 1:
			if (player.Gold < HealthPrice)
			{
				printf("골드가 부족합니다\n");
				break;
			}
			printf("체력 + 100\n");
			player.Health += 1.0f;
			player.Gold -= 100;
			break;
		case 2:
			if (player.Gold < PowerPrice)
			{
				printf("골드가 부족합니다\n");
				break;
			}
			printf("공격력 + 10\n");
			player.Power += 0.1f;
			player.Gold -= 100;
			break;
		case 3:
			if (player.Gold < BatLengthPrice)
			{
				printf("골드가 부족합니다\n");
				break;
			}
			printf("배트 길이 + 1\n");
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
		NewEnemy = new RookiePitcher("루키", 1.0f, 0.1f, 200);
		break;
	case 1:
		NewEnemy = new CloneMaster("클론 마스터", 1.2f, 0.15f, 300);
		break;
	case 2:
		NewEnemy = new Gangsoku("강속구", 1.1f, 0.2f, 350);
		break;
	default:
		break;
	}
	return NewEnemy;
}

Enemy* GameManager::AppearChampion()
{
	Enemy* LastEnemy = new Champion("챔피언", 10.0f, 2.5f, 100000000);
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
		printf("죽었습니다\n");
	}
	else
	{
		printf("승리!");
	}
}
