#include "Core.h"

namespace Core
{
	__int64 GetEnoughCapacity(__int64 const capacity, __int64 const count)
	{
		__int64 result = capacity == _0 ? _1 : capacity;
		do
		{
			result += result;
			if (result < _0)
			{
				result = _integerMaxUnsigned;
				break;
			}
		}
		while (result < count);
		return result;
	}
}