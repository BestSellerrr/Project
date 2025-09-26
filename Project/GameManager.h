#pragma once
#include "Player.h"
#include "Enemy.h"
#include"StrikeZoneArray.h"

class GameManager
{
public:
	// �⺻ ȭ�� ��� �� ���� ����
	void Play();

	//�޴� ���
	void PrintMenu();

	//�Է��� �޴��� ���� ���Ӱ� ����, ���� ��� �Լ�
	void InputMenu();

	//���� �Լ�
	void Game(Enemy& InEnemy);

	//���� �Լ�
	void Shop();

	// �����ϰ� �� ������Ű�� �Լ�
	Enemy* RandomEnemy();

	//������ 10���������� ������ ���� ���� �Լ�
	Enemy* AppearChampion();

	//���������� ���� ���� �ɷ�ġ ��ȭ �Լ�
	void UpdateStatsFromStage(Enemy* InEnemy, int* InStage);

	//��� ��� �Լ�
	void PrintResult();
	
	//���� ���� ���� �÷��̾ �ֵθ� ��ġ�� ������ �Ǻ��ϴ� �Լ�
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

	//�÷��̾��� ����� ���ߴ��� Ȯ���ϴ� �Լ�
	inline bool IsPlayerDie(Player& InPlayer) { return InPlayer.Life <= 0.0f; };

	GameManager() = default;

public:
	//���� ���� ����
	const int HealthPrice = 100;
	const int PowerPrice = 100;
	const int BatLengthPrice = 1000;

	Enemy enemy;

	Player player;

	StrikeZoneArray strikezonearray;

};

