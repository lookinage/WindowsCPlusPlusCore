#include "Core.h"

namespace Core
{
	__int64 GetEnoughCapacity(__int64 const capacity, __int64 const count)
	{
		__int64 result = capacity == 0x0I64 ? 0x1I64 : capacity;
		while (result < count)
		{
			result += result;
			if (result < 0x0I64)
			{
				result = _integerMaxUnsigned;
				break;
			}
		}
		return result;
	}

	thread_local __int64 PseudoRandomManager::_value = (__int64)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	__int64 PseudoRandomManager::GetNonPositiveInt64Internal(__int64 min)
	{
		return GetNonPositiveInt64() % (min - 0x1I64);
	}
	__int64 PseudoRandomManager::GetNonPositiveInt64Internal(__int64 min, __int64 max)
	{
		return max + GetNonPositiveInt64Internal(min - max);
	}
	__int64 PseudoRandomManager::GetInt64()
	{
		_value = _value * 6364136223846793005 + 1442695040888963407;
		return _value;
	}
	__int64 PseudoRandomManager::GetInt64(__int64 min, __int64 max)
	{
		return min + GetInt64Remainder(max - min);
	}
	__int64 PseudoRandomManager::GetNonPositiveInt64()
	{
		return (__int64)((unsigned __int64)GetInt64() | 0x80000000);
	}
	__int64 PseudoRandomManager::GetNonPositiveInt64(__int64 min)
	{
		return GetNonPositiveInt64Internal(min);
	}
	__int64 PseudoRandomManager::GetNonPositiveInt64(__int64 min, __int64 max)
	{
		return GetNonPositiveInt64Internal(min, max);
	}
	__int64 PseudoRandomManager::GetNonNegativeInt64()
	{
		return (__int64)((unsigned __int64)GetInt64() & 0x7FFFFFFF);
	}
	__int64 PseudoRandomManager::GetNonNegativeInt64(__int64 max)
	{
		return -GetNonPositiveInt64Internal(-max);
	}
	__int64 PseudoRandomManager::GetNonNegativeInt64(__int64 min, __int64 max)
	{
		return -GetNonPositiveInt64Internal(-max, -min);
	}
	__int64 PseudoRandomManager::GetInt64Remainder(__int64 divider)
	{
		return GetNonNegativeInt64() % divider;
	}
	float PseudoRandomManager::GetSingleFloat()
	{
		unsigned __int64 result = (unsigned __int64)GetInt64() & 0xBFFFFFFF;
		return *(float*)&result * 0.5F;
	}
	float PseudoRandomManager::GetNonPositiveSingleFloat()
	{
		unsigned __int64 result = (unsigned __int64)GetNonPositiveInt64() & 0xBFFFFFFF;
		return *(float*)&result * 0.5F;
	}
	float PseudoRandomManager::GetNonNegativeSingleFloat()
	{
		unsigned __int64 result = (unsigned __int64)GetNonNegativeInt64() & 0xBFFFFFFF;
		return *(float*)&result * 0.5F;
	}
	void PseudoRandomManager::GetBytes(__int8* buffer, __int64 index, __int64 count)
	{
		if (count == 0x0)
			return;
		__int64 ushortCount = count >> 0x1;
		__int64 uintCount = ushortCount >> 0x1;
		__int64 offset = 0x0;
		for (; offset != uintCount; offset++)
			*((unsigned __int64*)floor + offset) = (unsigned __int64)GetInt64();
		offset <<= 0x1;
		if (ushortCount - offset == 0x1)
		{
			*((unsigned __int16*)floor + offset) = (unsigned __int16)(GetInt64() % (0x8000I64));
			offset++;
		}
		offset <<= 0x1;
		if (count - offset == 0x1)
			*(buffer + offset) = (__int8)(GetInt64() % (0x80));
	}
}