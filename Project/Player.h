#pragma once
#include "StrikeZoneArray.h"

class Player : public StrikeZoneArray
{
public:

	//플레이어의 배열 출력(야구판)
	void PlayerArray();

	//플레이어의 정보 출력
	void PlayerStatInfo();
	
	//플레이어가 칠 좌표 입력 받고, 배트의 길이에 따라 칠 좌표 입력하는 함수
	void Hit(int* InX, int* InY, int* InBatLength);

	//플레이어의 스킬 사용
	void UseUlt();

	//플레이어의 스킬 사용후 스킬종료
	void ResetUlt();

	//플레이어가 때릴 때마다 궁극기가 차는 함수
	void MoveUpBase();

	//플레이어의 궁극기 게이지가 꽉 찼는지 확인하는 함수
	bool IsPlayerMaxUltGauge();

	//플레이어가 궁극기 게이지가 꽉 찼을 때 궁극기 사용하는 함수
	void PlayerPrintUlt();

	//플레이어의 정보 출력하기 위한 Getter
	inline const float GetPlayerHealth() const { return Health; }
	inline const float GetPlayerPower() const { return Power; }
	inline const int GetPlayerBatLength() const { return BatLength; }
	inline const int GetPlayerUltNumber() const { return UltNumber; }
	inline const int GetPlayerUltGauge() const { return UltGauge; }


	Player() = default;

public:
	//플레이어의 기본 설정
	int Life = 5;
	float Health = 1.0f;
	float Power = 0.2f;
	int BatLength = 3;
	int Gold = 0;

	//플레이어 궁극기 사용을 위한 변수 선언
	unsigned int UltGauge = 0;
	unsigned int UltNumber = 0;
	const unsigned int MaxUltGauge = 100;
	bool UltOnOff = false;

	//플레이어 궁극기 게이지를 세팅하기 위한 Setter
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

