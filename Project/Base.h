#pragma once

enum class BasePlag
{
	FirstBase =  1 << 0,
	SecondBase = 1 << 1,
	ThirdBase =  1 << 2,
	HomeBase =   1 << 3,
};

class Base
{
public:
	inline bool IsHomeRun(int* PlayerUltPlag);

public:
	int ResetHomeBase = 0b0111;
};

