#pragma once
enum class StrikeZone
{
	Empty = 0,
	Strike,
	Ball
};

class StrikeZoneArray
{
public:



	StrikeZoneArray()
	{
		for (int i = 0; i < ZoneSize; i++)
		{
			for (int j = 0; j < ZoneSize; j++)
			{
				for (int k = 0; k < ZoneSize; k++)
				{
					Strike[i][j][k] = StrikeZone::Empty;
				}
			}
		}
	}

public:
	static constexpr int ZoneSize = 5;

protected:
	StrikeZone Strike[ZoneSize][ZoneSize][ZoneSize];
};

