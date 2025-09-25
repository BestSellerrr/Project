#pragma once
#include "Player.h"
#include "Enemy.h"
#include"StrikeZoneArray.h"

class GameManager
{
public:
	void Play();

	void PrintMenu();

	void InputMenu();

	void Game(Enemy& InEnemy);

	void Shop();

	Enemy* RandomEnemy();

	Enemy* AppearChampion();

	void PrintResult();

	void UpdateStatsFromStage(Enemy* InEnemy, int* InStage);
	
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

	inline bool IsPlayerDie(Player& InPlayer) { return InPlayer.Life <= 0.0f; };


	GameManager() = default;

public:
	static constexpr int MaxTurn = 7;
	int RemainTurn = MaxTurn;

	const int HealthPrice = 100;
	const int PowerPrice = 100;
	const int BatLengthPrice = 1000;

	Enemy enemy;

	Player player;

	StrikeZoneArray strikezonearray;

};

