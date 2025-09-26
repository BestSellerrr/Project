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
	//배열 초기화를 위한 함수
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

	//생성자를 통한 기본 배열 선언
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

	//배열의 스트라이크존을 판별하기 위한 함수
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

	//배열내에 공이 있는지 판별하는 함수
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

	//스트라이크존의 범위를 판별하는 함수
	inline static bool IsInStrikeZone(int InX, int InY)
	{
		return (InX > 0 && InX < (ZoneSize - 1)) 
			&& (InY > 0 && InY < (ZoneSize - 1));
	}

	//공을 던질 수 있는 범위를 판별하는 함수
	inline static bool IsInPitchZone(int InX, int InY)
	{
		return (InX >= 0 && InX < ZoneSize) 
			&& (InY >= 0 && InY < ZoneSize);
	}


public:
	//기본 배열 크기
	static constexpr int ZoneSize = 5;
	StrikeZoneCell Strike[ZoneSize][ZoneSize];
};

