#pragma once
#include "StrikeZoneArray.h"

class Player : public StrikeZoneArray
{
public:

	void PlayerArray();
	
	void Hit();

	void Stand();



public:

	static constexpr int MaxTurn = 7;

	int RemainTurn = MaxTurn;

	float Power = 0.05f;
	float HitAvr = 0.05f;
	unsigned int UltGauge = 0;
};

