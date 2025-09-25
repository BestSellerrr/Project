#pragma once
#include "StrikeZoneArray.h"

class Player : public StrikeZoneArray
{
public:

	void PlayerArray();

	void PlayerStatInfo();
	
	void Hit(int* InX, int* InY, int* InBatLength);

	void Stand();

	inline const float GetPlayerHealth() const { return Health; }
	inline const float GetPlayerPower() const { return Power; }
	inline const int GetPlayerBatLength() const { return BatLength; }


	Player() = default;

public:
	int Life = 3;
	float Health = 1.0f;
	float Power = 0.2f;
	int BatLength = 3;
	unsigned int UltGauge = 0;
	int Gold = 0;
};

