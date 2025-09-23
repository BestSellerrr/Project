#pragma once
class Player
{
public:

	void PlayerArray();

	void PrintPlayerArray();
	
	void Hit();

	void Stand();



public:

	static constexpr int MaxTurn = 7;

	int RemainTurn = MaxTurn;

	float Power = 0.05f;
	float HitAvr = 0.05f;
};

