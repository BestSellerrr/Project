#pragma once
#include "StrikeZoneArray.h"

#include <string>

class Enemy : public StrikeZoneArray
{
public:
	//적의 배열 출력(야구판)
	void EnemyArray();

	//적의 정보 출력
	void EnemyStatInfo();

	//적이 던질 수 있는 만큼 배열에 표시하는 함수
	void Throw(int InStartingBallCount);

	//적의 스킬사용
	virtual void Skill();

	//적의 스킬사용후 스킬종료
	virtual void SkillOff();

	//적의 스킬게이지가 꽉찼는지 확인하는 함수
	bool IsEnemyMaxSkillGauge(Enemy* InEnemy);

	//적의 스킬게이지가 꽉찼을 때 스킬을 발동시키는 함수
	void EnemyPrintSkill(Enemy* InEnemy);
	

	//적의 정보를 출력하기 위한 Getter
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
	//Enemy의 기본 정보
	std::string EnemyName = "상대";
	float Health = 1.0f;
	float Power = 0.1f;
	int DropGold = 100;

	//스킬 게이지 관련 변수 선언
	float SkillGauge = 0.0f;
	const float MaxSkillGauge = 1.0f;
	bool SkillOnOff = false;

	int PitchCount = 15;
	const int MaxPitchCount = 15;

	//스테이지에 따른 적의 스텟 변화를 위한 변수 선언
	int Stage = 0;
	const int MaxStage = 10;

	//적의 스킬 게이지 세팅을 위한 Setter
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

	//적의 스테이지 세팅을 위한 Setter
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

	//적이 던질 수 있는 공의 수를 세팅하기 위한 함수
	inline void SetPitchCount(int InPitchCount)
	{
		if (InPitchCount > MaxPitchCount)
		{
			PitchCount = MaxPitchCount;
		}
		else if (InPitchCount < 0)
		{
			PitchCount = 0;
		}
		else
		{
			PitchCount = InPitchCount;
		}
	}

};

