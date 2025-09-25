#pragma once
#include "StrikeZoneArray.h"

#include <string>

class Enemy : public StrikeZoneArray
{
public:

	void EnemyArray();

	void EnemyStatInfo();

	void Throw(int InStartingBallCount);

	
	inline const std::string& GetEnemyName() const { return EnemyName; }
	inline const float GetEnemyHealth() const { return Health; }
	inline const float GetEnemyPower() const { return Power; }
	inline const int GetEnemyDropGold() const { return DropGold; }
	inline const float GetEnemySkillGauge() const { return SkillGauge; }



	Enemy() = default;
	Enemy(std::string InName, float InHealth, float InPower, int InDropGold)
		:EnemyName(InName), Health(InHealth), Power(InPower), DropGold(InDropGold)
	{ }
	virtual ~Enemy() = default;


public:
	std::string EnemyName = "»ó´ë";
	float Health = 1.0f;
	float Power = 0.1f;
	int DropGold = 100;

	float SkillGauge = 0.1f;
	float MaxSkillGauge = 1.0f;

	int CanThrowBall = 15;

	int Stage = 0;
	const int MaxStage = 10;

	inline void SetEnemySkillGauge(float InEnemySkillGauge)
	{
		if (InEnemySkillGauge > MaxSkillGauge)
		{
			SkillGauge = MaxSkillGauge;
		}
		else if (InEnemySkillGauge < 0.0f)
		{
			SkillGauge = 0.0f;
		}
		else
		{
			SkillGauge = InEnemySkillGauge;
		}
	}

	inline void SetStage(int InStage)
	{
		if (InStage > MaxStage)
		{
			Stage = MaxStage;
		}
		else if (InStage < 0)
		{
			Stage = 0;
		}
		else
		{
			Stage = InStage;
		}
	}
};

