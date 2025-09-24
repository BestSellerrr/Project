#include "Base.h"

inline bool Base::IsHomeRun(int* PlayerUltPlag)
{
	if ((*PlayerUltPlag & static_cast<int>(BasePlag::HomeBase)) == static_cast<int>(BasePlag::HomeBase))
	{
		return true;
	}
	return false;
}
