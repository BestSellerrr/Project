#pragma once
#include "StrikeZoneArray.h"

#include <string>

class Enemy : public StrikeZoneArray
{
public:
	//���� �迭 ���(�߱���)
	void EnemyArray();

	//���� ���� ���
	void EnemyStatInfo();

	//���� ���� �� �ִ� ��ŭ �迭�� ǥ���ϴ� �Լ�
	void Throw(int InStartingBallCount);

	//���� ��ų���
	virtual void Skill();

	//���� ��ų����� ��ų����
	virtual void SkillOff();

	//���� ��ų�������� ��á���� Ȯ���ϴ� �Լ�
	bool IsEnemyMaxSkillGauge(Enemy* InEnemy);

	//���� ��ų�������� ��á�� �� ��ų�� �ߵ���Ű�� �Լ�
	void EnemyPrintSkill(Enemy* InEnemy);
	

	//���� ������ ����ϱ� ���� Getter
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
	//Enemy�� �⺻ ����
	std::string EnemyName = "���";
	float Health = 1.0f;
	float Power = 0.1f;
	int DropGold = 100;

	//��ų ������ ���� ���� ����
	float SkillGauge = 0.0f;
	const float MaxSkillGauge = 1.0f;
	bool SkillOnOff = false;

	int PitchCount = 15;
	const int MaxPitchCount = 15;

	//���������� ���� ���� ���� ��ȭ�� ���� ���� ����
	int Stage = 0;
	const int MaxStage = 10;

	//���� ��ų ������ ������ ���� Setter
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

	//���� �������� ������ ���� Setter
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

	//���� ���� �� �ִ� ���� ���� �����ϱ� ���� �Լ�
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

