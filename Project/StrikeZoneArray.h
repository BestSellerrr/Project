#pragma once
enum class StrikeZoneCell
{
	Empty = 0,
	Strike,
	Ball
};

class StrikeZoneArray
{

	virtual void PrintStrikeZone() = 0;

public:

	StrikeZoneArray()
	{
		for (int i = 0; i < ZoneSize; i++)
		{
			for (int j = 0; j < ZoneSize; j++)
			{
				if ((i > 0 && i < ZoneSize)
				 && (j > 0 && j < ZoneSize))
				{
					Strike[i][j] = StrikeZoneCell::Strike;
				}
				else
				{
					Strike[i][j] = StrikeZoneCell::Empty;
				}
			}
		}
	}
	virtual ~StrikeZoneArray() = default;

	inline bool IsStrike(int InX, int InY) const
	{
		if (IsInStrikeZone(InX, InY))
		{
			return Strike[InX][InY] == StrikeZoneCell::Strike;
		}
		return false;
	}

	inline static bool IsInStrikeZone(int InX, int InY)
	{
		return InX > 0 && InX < ZoneSize && InY > 0 && InY < ZoneSize;
	}

	inline static bool IsInPitchZone(int InX, int InY)
	{
		return InX >= 0 && InX <= ZoneSize && InY >= 0 && InY <= ZoneSize;
	}

public:
	static constexpr int ZoneSize = 5;

protected:
	StrikeZoneCell Strike[ZoneSize][ZoneSize];
};

