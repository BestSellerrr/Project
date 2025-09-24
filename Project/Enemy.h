#pragma once
#include "StrikeZoneArray.h"

class Enemy : public StrikeZoneArray
{
public:

	void EnemyArray();

	void Throw(int InStartingBallCount);

public:
	int Stage = 0;
	int StartBallCount = 0;

};

