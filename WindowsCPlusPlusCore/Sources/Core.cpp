#include "Core.h"

namespace Core
{
	__int64 GetEnoughCapacity(__int64 const capacity, __int64 const count)
	{
		__int64 result = capacity == 0x0I64 ? 0x1I64 : capacity;
		do
		{
			result += result;
			if (result < 0x0I64)
			{
				result = _integerMaxUnsigned;
				break;
			}
		}
		while (result < count);
		return result;
	}
}