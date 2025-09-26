#pragma once
enum class StrikeZoneCell
{
	Empty = 0,
	Strike,
	Ball
};

class StrikeZoneArray
{
public:
	//�迭 �ʱ�ȭ�� ���� �Լ�
	inline void ArrayReset()
	{
		for (int i = 0; i < ZoneSize; i++)
		{
			for (int j = 0; j < ZoneSize; j++)
			{
				Strike[i][j] = StrikeZoneCell::Empty;
			}
		}
	}

	//�����ڸ� ���� �⺻ �迭 ����
	StrikeZoneArray()
	{
		for (int i = 0; i < ZoneSize; i++)
		{
			for (int j = 0; j < ZoneSize; j++)
			{
				Strike[i][j] = StrikeZoneCell::Empty;			
			}
		}
	}

public:

	//�迭�� ��Ʈ����ũ���� �Ǻ��ϱ� ���� �Լ�
	inline bool IsStrike(int* InX, int* InY) const
	{
		if (IsInPitchZone(*InX, *InY))
		{
			if (IsInStrikeZone(*InX, *InY))
			{
				return Strike[*InY][*InX] == StrikeZoneCell::Strike;
			}
		}		
		return false;
	}

	//�迭���� ���� �ִ��� �Ǻ��ϴ� �Լ�
	inline bool IsBallInZone(int* InX, int* InY) const
	{
		if (IsInPitchZone(*InX, *InY))
		{
			if (Strike[*InY][*InX] != StrikeZoneCell::Empty)
			{
				return true;
			} 
		}		
		return false;
	}

	//��Ʈ����ũ���� ������ �Ǻ��ϴ� �Լ�
	inline static bool IsInStrikeZone(int InX, int InY)
	{
		return (InX > 0 && InX < (ZoneSize - 1)) 
			&& (InY > 0 && InY < (ZoneSize - 1));
	}

	//���� ���� �� �ִ� ������ �Ǻ��ϴ� �Լ�
	inline static bool IsInPitchZone(int InX, int InY)
	{
		return (InX >= 0 && InX < ZoneSize) 
			&& (InY >= 0 && InY < ZoneSize);
	}


public:
	//�⺻ �迭 ũ��
	static constexpr int ZoneSize = 5;
	StrikeZoneCell Strike[ZoneSize][ZoneSize];
};

