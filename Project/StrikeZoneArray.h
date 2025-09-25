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

	inline static bool IsInStrikeZone(int InX, int InY)
	{
		return (InX > 0 && InX < (ZoneSize - 1)) 
			&& (InY > 0 && InY < (ZoneSize - 1));
	}

	inline static bool IsInPitchZone(int InX, int InY)
	{
		return (InX >= 0 && InX < ZoneSize) 
			&& (InY >= 0 && InY < ZoneSize);
	}


public:
	static constexpr int ZoneSize = 5;
	StrikeZoneCell Strike[ZoneSize][ZoneSize];
};

