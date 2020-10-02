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

	thread_local bool PseudoRandomManager::_initialized;
	thread_local __int32 PseudoRandomManager::_seeds[0x38I64];
	thread_local __int32 PseudoRandomManager::_inext;
	thread_local __int32 PseudoRandomManager::_inextp;

	void PseudoRandomManager::Initialize()
	{
		__int32 seed = (__int32)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		__int32 subtraction = seed == 0x80000000I32 ? 0x7FFFFFFFI32 : std::abs(seed);
		__int32 mj = 0x9A4EC86I32 - subtraction;
		_seeds[0x37I32] = mj;
		__int32 mk = 0x1I32;
		for (__int32 i = 0x1I32; i < 0x37I32; i++)
		{
			__int32 ii = 0x15I32 * i % 0x37I32;
			_seeds[ii] = mk;
			mk = mj - mk;
			if (mk < 0x0I32)
				mk += 0x7FFFFFFFI32;
			mj = _seeds[ii];
		}
		for (__int32 k = 0x1I32; k < 0x5I32; k++)
			for (__int32 i = 0x1I32; i < 0x38I32; i++)
			{
				_seeds[i] -= _seeds[0x1I32 + (i + 0x1EI32) % 0x37I32];
				if (_seeds[i] < 0x0I32)
					_seeds[i] += 0x7FFFFFFFI32;
			}
		_inext = 0x0I32;
		_inextp = 0x15I32;
	}
	__int32 PseudoRandomManager::GetNonPositiveInt32Internal(__int32 min)
	{
		return GetNonPositiveInt32() % (min - 0x1I32);
	}
	__int32 PseudoRandomManager::GetNonPositiveInt32Internal(__int32 min, __int32 max)
	{
		return max + GetNonPositiveInt32Internal(min - max);
	}
	__int32 PseudoRandomManager::GetInt32()
	{
		if (!_initialized)
		{
			_initialized = true;
			Initialize();
		}
		if (++_inext >= 0x38I32)
			_inext = 0x1I32;
		if (++_inextp >= 0x38I32)
			_inextp = 0x1I32;
		__int32 result = _seeds[_inext] - _seeds[_inextp];
		_seeds[_inext] = result < 0x0I32 ? result + 0x7FFFFFFFI32 : result == 0x7FFFFFFFI32 ? 0x7FFFFFFFI32 - 0x1I32 : result;
		return result;
	}
	__int32 PseudoRandomManager::GetInt32(__int32 min, __int32 max)
	{
		return (__int32)(max - ((__int64)0x7FFFFFFFI32 + GetInt32()) % (-0x1I64 + min - max));
	}
	__int32 PseudoRandomManager::GetNonPositiveInt32()
	{
		return (__int32)((unsigned __int32)GetInt32() | 0x80000000);
	}
	__int32 PseudoRandomManager::GetNonPositiveInt32(__int32 min)
	{
		return GetNonPositiveInt32Internal(min);
	}
	__int32 PseudoRandomManager::GetNonPositiveInt32(__int32 min, __int32 max)
	{
		return GetNonPositiveInt32Internal(min, max);
	}
	__int32 PseudoRandomManager::GetNonNegativeInt32()
	{
		return (__int32)((unsigned __int32)GetInt32() & 0x7FFFFFFF);
	}
	__int32 PseudoRandomManager::GetNonNegativeInt32(__int32 max)
	{
		return -GetNonPositiveInt32Internal(-max);
	}
	__int32 PseudoRandomManager::GetNonNegativeInt32(__int32 min, __int32 max)
	{
		return -GetNonPositiveInt32Internal(-max, -min);
	}
	__int32 PseudoRandomManager::GetInt32Remainder(__int32 divider)
	{
		return GetNonNegativeInt32() % divider;
	}
	float PseudoRandomManager::GetSingleFloat()
	{
		unsigned __int32 result = (unsigned __int32)GetInt32() & 0xBFFFFFFF;
		return *(float*)&result * 0.5F;
	}
	float PseudoRandomManager::GetNonPositiveSingleFloat()
	{
		unsigned __int32 result = (unsigned __int32)GetNonPositiveInt32() & 0xBFFFFFFF;
		return *(float*)&result * 0.5F;
	}
	float PseudoRandomManager::GetNonNegativeSingleFloat()
	{
		unsigned __int32 result = (unsigned __int32)GetNonNegativeInt32() & 0xBFFFFFFF;
		return *(float*)&result * 0.5F;
	}
	void PseudoRandomManager::GetBytes(__int8* buffer, __int32 index, __int32 count)
	{
		if (count == 0x0)
			return;
		__int32 ushortCount = count >> 0x1;
		__int32 uintCount = ushortCount >> 0x1;
		__int32 offset = 0x0;
		for (; offset != uintCount; offset++)
			*((unsigned __int32*)floor + offset) = (unsigned __int32)GetInt32();
		offset <<= 0x1;
		if (ushortCount - offset == 0x1)
		{
			*((unsigned __int16*)floor + offset) = (unsigned __int16)(GetInt32() % (0x8000I32));
			offset++;
		}
		offset <<= 0x1;
		if (count - offset == 0x1)
			*(buffer + offset) = (__int8)(GetInt32() % (0x80));
	}
}