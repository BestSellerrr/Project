#pragma once
#include "StrikeZoneArray.h"

class Player : public StrikeZoneArray
{
public:

	//�÷��̾��� �迭 ���(�߱���)
	void PlayerArray();

	//�÷��̾��� ���� ���
	void PlayerStatInfo();
	
	//�÷��̾ ĥ ��ǥ �Է� �ް�, ��Ʈ�� ���̿� ���� ĥ ��ǥ �Է��ϴ� �Լ�
	void Hit(int* InX, int* InY, int* InBatLength);

	//�÷��̾��� ��ų ���
	void UseUlt();

	//�÷��̾��� ��ų ����� ��ų����
	void ResetUlt();

	//�÷��̾ ���� ������ �ñرⰡ ���� �Լ�
	void MoveUpBase();

	//�÷��̾��� �ñر� �������� �� á���� Ȯ���ϴ� �Լ�
	bool IsPlayerMaxUltGauge();

	//�÷��̾ �ñر� �������� �� á�� �� �ñر� ����ϴ� �Լ�
	void PlayerPrintUlt();

	//�÷��̾��� ���� ����ϱ� ���� Getter
	inline const float GetPlayerHealth() const { return Health; }
	inline const float GetPlayerPower() const { return Power; }
	inline const int GetPlayerBatLength() const { return BatLength; }
	inline const int GetPlayerUltNumber() const { return UltNumber; }
	inline const int GetPlayerUltGauge() const { return UltGauge; }


	Player() = default;

public:
	//�÷��̾��� �⺻ ����
	int Life = 5;
	float Health = 1.0f;
	float Power = 0.2f;
	int BatLength = 3;
	int Gold = 0;

	//�÷��̾� �ñر� ����� ���� ���� ����
	unsigned int UltGauge = 0;
	unsigned int UltNumber = 0;
	const unsigned int MaxUltGauge = 100;
	bool UltOnOff = false;

	//�÷��̾� �ñر� �������� �����ϱ� ���� Setter
	inline void SetUltGauge(unsigned int InUltGauge)
	{
		if (InUltGauge > MaxUltGauge)
		{
			UltGauge = MaxUltGauge;
		}
		else if (InUltGauge < 0)
		{
			UltGauge = 0;
		}
		else
		{
			UltGauge = InUltGauge;
		}
	}
};

