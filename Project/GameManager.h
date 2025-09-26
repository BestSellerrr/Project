#pragma once
#include "Player.h"
#include "Enemy.h"
#include"StrikeZoneArray.h"

class GameManager
{
public:
	// 기본 화면 출력 및 게임 실행
	void Play();

	//메뉴 출력
	void PrintMenu();

	//입력한 메뉴에 따라 게임과 상점, 정보 출력 함수
	void InputMenu();

	//게임 함수
	void Game(Enemy& InEnemy);

	//상점 함수
	void Shop();

	// 랜덤하게 적 출현시키는 함수
	Enemy* RandomEnemy();

	//마지막 10스테이지에 나오는 보스 출현 함수
	Enemy* AppearChampion();

	//스테이지에 따른 적의 능력치 변화 함수
	void UpdateStatsFromStage(Enemy* InEnemy, int* InStage);

	//결과 출력 함수
	void PrintResult();
	
	//적이 던진 공과 플레이어가 휘두른 위치가 같은지 판별하는 함수
	inline bool IsPlayerHit(const Player& InPlayer,const Enemy& InEnemy)
	{
		for (int y = 0; y < strikezonearray.ZoneSize; y++)
		{
			for (int x = 0; x < strikezonearray.ZoneSize; x++)
			{
				if ((InPlayer.Strike[y][x] != StrikeZoneCell::Empty)
				  && (InEnemy.Strike[y][x] != StrikeZoneCell::Empty))
					return true;
			}
		}
		return false;
	}

	//플레이어의 목숨이 다했는지 확인하는 함수
	inline bool IsPlayerDie(Player& InPlayer) { return InPlayer.Life <= 0.0f; };

	GameManager() = default;

public:
	//상점 가격 설정
	const int HealthPrice = 100;
	const int PowerPrice = 100;
	const int BatLengthPrice = 1000;

	Enemy enemy;

	Player player;

	StrikeZoneArray strikezonearray;

};

