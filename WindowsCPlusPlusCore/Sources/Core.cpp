#include "Core.h"

namespace Core
{
	__int64 GetEnoughCapacity(__int64 const capacity, __int64 const count)
	{
		__int64 result;

		result = capacity == IntegerZero ? IntegerOne : capacity;
		do
		{
			result += result;
			if (result < IntegerZero)
			{
				result = IntegerMaxUnsigned;
				break;
			}
		}
		while (result < count);
		return result;
	}
}