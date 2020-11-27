#include <Core.h>

using namespace Core;

__int64 const GetSimplifiedValueTest()
{
	class SixteenByteSizeValue
	{
		__int8 _firstValue;
		__int8 _secondValue;
		__int8 _thirdValue;
		__int8 _fourthValue;
		__int8 _fifthValue;
		__int8 _sixthValue;
		__int8 _seventhValue;
		__int8 _eighthValue;
		__int8 _ninthValue;
		__int8 _tenthValue;
		__int8 _eleventhValue;
		__int8 _twelfthValue;
		__int8 _thirteenthValue;
		__int8 _fourteenthValue;
		__int8 _fifteenthValue;
		__int8 _sixteenthValue;

	public:

		SixteenByteSizeValue(__int64 firstValue, __int64 secondValue) : _firstValue((__int8)firstValue), _secondValue((__int8)(firstValue >> 0x8I64)), _thirdValue((__int8)(firstValue >> 0x10I64)), _fourthValue((__int8)(firstValue >> 0x18I64)), _fifthValue((__int8)(firstValue >> 0x20I64)), _sixthValue((__int8)(firstValue >> 0x28I64)), _seventhValue((__int8)(firstValue >> 0x30I64)), _eighthValue((__int8)(firstValue >> 0x38I64)), _ninthValue((__int8)secondValue), _tenthValue((__int8)(secondValue >> 0x8I64)), _eleventhValue((__int8)(secondValue >> 0x10I64)), _twelfthValue((__int8)(secondValue >> 0x18I64)), _thirteenthValue((__int8)(secondValue >> 0x20I64)), _fourteenthValue((__int8)(secondValue >> 0x28I64)), _fifteenthValue((__int8)(secondValue >> 0x30I64)), _sixteenthValue((__int8)(secondValue >> 0x38I64)) { }
	};
	class FifteenByteSizeValue
	{
		__int8 _firstValue;
		__int8 _secondValue;
		__int8 _thirdValue;
		__int8 _fourthValue;
		__int8 _fifthValue;
		__int8 _sixthValue;
		__int8 _seventhValue;
		__int8 _eighthValue;
		__int8 _ninthValue;
		__int8 _tenthValue;
		__int8 _eleventhValue;
		__int8 _twelfthValue;
		__int8 _thirteenthValue;
		__int8 _fourteenthValue;
		__int8 _fifteenthValue;

	public:

		FifteenByteSizeValue(__int64 firstValue, __int64 secondValue) : _firstValue((__int8)firstValue), _secondValue((__int8)(firstValue >> 0x8I64)), _thirdValue((__int8)(firstValue >> 0x10I64)), _fourthValue((__int8)(firstValue >> 0x18I64)), _fifthValue((__int8)(firstValue >> 0x20I64)), _sixthValue((__int8)(firstValue >> 0x28I64)), _seventhValue((__int8)(firstValue >> 0x30I64)), _eighthValue((__int8)(firstValue >> 0x38I64)), _ninthValue((__int8)secondValue), _tenthValue((__int8)(secondValue >> 0x8I64)), _eleventhValue((__int8)(secondValue >> 0x10I64)), _twelfthValue((__int8)(secondValue >> 0x18I64)), _thirteenthValue((__int8)(secondValue >> 0x20I64)), _fourteenthValue((__int8)(secondValue >> 0x28I64)), _fifteenthValue((__int8)(secondValue >> 0x30I64)) { }
	};
	class FourteenByteSizeValue
	{
		__int8 _firstValue;
		__int8 _secondValue;
		__int8 _thirdValue;
		__int8 _fourthValue;
		__int8 _fifthValue;
		__int8 _sixthValue;
		__int8 _seventhValue;
		__int8 _eighthValue;
		__int8 _ninthValue;
		__int8 _tenthValue;
		__int8 _eleventhValue;
		__int8 _twelfthValue;
		__int8 _thirteenthValue;
		__int8 _fourteenthValue;

	public:

		FourteenByteSizeValue(__int64 firstValue, __int64 secondValue) : _firstValue((__int8)firstValue), _secondValue((__int8)(firstValue >> 0x8I64)), _thirdValue((__int8)(firstValue >> 0x10I64)), _fourthValue((__int8)(firstValue >> 0x18I64)), _fifthValue((__int8)(firstValue >> 0x20I64)), _sixthValue((__int8)(firstValue >> 0x28I64)), _seventhValue((__int8)(firstValue >> 0x30I64)), _eighthValue((__int8)(firstValue >> 0x38I64)), _ninthValue((__int8)secondValue), _tenthValue((__int8)(secondValue >> 0x8I64)), _eleventhValue((__int8)(secondValue >> 0x10I64)), _twelfthValue((__int8)(secondValue >> 0x18I64)), _thirteenthValue((__int8)(secondValue >> 0x20I64)), _fourteenthValue((__int8)(secondValue >> 0x28I64)) { }
	};
	class ThirteenByteSizeValue
	{
		__int8 _firstValue;
		__int8 _secondValue;
		__int8 _thirdValue;
		__int8 _fourthValue;
		__int8 _fifthValue;
		__int8 _sixthValue;
		__int8 _seventhValue;
		__int8 _eighthValue;
		__int8 _ninthValue;
		__int8 _tenthValue;
		__int8 _eleventhValue;
		__int8 _twelfthValue;
		__int8 _thirteenthValue;

	public:

		ThirteenByteSizeValue(__int64 firstValue, __int64 secondValue) : _firstValue((__int8)firstValue), _secondValue((__int8)(firstValue >> 0x8I64)), _thirdValue((__int8)(firstValue >> 0x10I64)), _fourthValue((__int8)(firstValue >> 0x18I64)), _fifthValue((__int8)(firstValue >> 0x20I64)), _sixthValue((__int8)(firstValue >> 0x28I64)), _seventhValue((__int8)(firstValue >> 0x30I64)), _eighthValue((__int8)(firstValue >> 0x38I64)), _ninthValue((__int8)secondValue), _tenthValue((__int8)(secondValue >> 0x8I64)), _eleventhValue((__int8)(secondValue >> 0x10I64)), _twelfthValue((__int8)(secondValue >> 0x18I64)), _thirteenthValue((__int8)(secondValue >> 0x20I64)) { }
	};
	class TwelveByteSizeValue
	{
		__int8 _firstValue;
		__int8 _secondValue;
		__int8 _thirdValue;
		__int8 _fourthValue;
		__int8 _fifthValue;
		__int8 _sixthValue;
		__int8 _seventhValue;
		__int8 _eighthValue;
		__int8 _ninthValue;
		__int8 _tenthValue;
		__int8 _eleventhValue;
		__int8 _twelfthValue;

	public:

		TwelveByteSizeValue(__int64 firstValue, __int64 secondValue) : _firstValue((__int8)firstValue), _secondValue((__int8)(firstValue >> 0x8I64)), _thirdValue((__int8)(firstValue >> 0x10I64)), _fourthValue((__int8)(firstValue >> 0x18I64)), _fifthValue((__int8)(firstValue >> 0x20I64)), _sixthValue((__int8)(firstValue >> 0x28I64)), _seventhValue((__int8)(firstValue >> 0x30I64)), _eighthValue((__int8)(firstValue >> 0x38I64)), _ninthValue((__int8)secondValue), _tenthValue((__int8)(secondValue >> 0x8I64)), _eleventhValue((__int8)(secondValue >> 0x10I64)), _twelfthValue((__int8)(secondValue >> 0x18I64)) { }
	};
	class ElevenByteSizeValue
	{
		__int8 _firstValue;
		__int8 _secondValue;
		__int8 _thirdValue;
		__int8 _fourthValue;
		__int8 _fifthValue;
		__int8 _sixthValue;
		__int8 _seventhValue;
		__int8 _eighthValue;
		__int8 _ninthValue;
		__int8 _tenthValue;
		__int8 _eleventhValue;

	public:

		ElevenByteSizeValue(__int64 firstValue, __int64 secondValue) : _firstValue((__int8)firstValue), _secondValue((__int8)(firstValue >> 0x8I64)), _thirdValue((__int8)(firstValue >> 0x10I64)), _fourthValue((__int8)(firstValue >> 0x18I64)), _fifthValue((__int8)(firstValue >> 0x20I64)), _sixthValue((__int8)(firstValue >> 0x28I64)), _seventhValue((__int8)(firstValue >> 0x30I64)), _eighthValue((__int8)(firstValue >> 0x38I64)), _ninthValue((__int8)secondValue), _tenthValue((__int8)(secondValue >> 0x8I64)), _eleventhValue((__int8)(secondValue >> 0x10I64)) { }
	};
	class TenByteSizeValue
	{
		__int8 _firstValue;
		__int8 _secondValue;
		__int8 _thirdValue;
		__int8 _fourthValue;
		__int8 _fifthValue;
		__int8 _sixthValue;
		__int8 _seventhValue;
		__int8 _eighthValue;
		__int8 _ninthValue;
		__int8 _tenthValue;

	public:

		TenByteSizeValue(__int64 firstValue, __int64 secondValue) : _firstValue((__int8)firstValue), _secondValue((__int8)(firstValue >> 0x8I64)), _thirdValue((__int8)(firstValue >> 0x10I64)), _fourthValue((__int8)(firstValue >> 0x18I64)), _fifthValue((__int8)(firstValue >> 0x20I64)), _sixthValue((__int8)(firstValue >> 0x28I64)), _seventhValue((__int8)(firstValue >> 0x30I64)), _eighthValue((__int8)(firstValue >> 0x38I64)), _ninthValue((__int8)secondValue), _tenthValue((__int8)(secondValue >> 0x8I64)) { }
	};
	class NineByteSizeValue
	{
		__int8 _firstValue;
		__int8 _secondValue;
		__int8 _thirdValue;
		__int8 _fourthValue;
		__int8 _fifthValue;
		__int8 _sixthValue;
		__int8 _seventhValue;
		__int8 _eighthValue;
		__int8 _ninthValue;

	public:

		NineByteSizeValue(__int64 firstValue, __int64 secondValue) : _firstValue((__int8)firstValue), _secondValue((__int8)(firstValue >> 0x8I64)), _thirdValue((__int8)(firstValue >> 0x10I64)), _fourthValue((__int8)(firstValue >> 0x18I64)), _fifthValue((__int8)(firstValue >> 0x20I64)), _sixthValue((__int8)(firstValue >> 0x28I64)), _seventhValue((__int8)(firstValue >> 0x30I64)), _eighthValue((__int8)(firstValue >> 0x38I64)), _ninthValue((__int8)secondValue) { }
	};
	class EightByteSizeValue
	{
		__int8 _firstValue;
		__int8 _secondValue;
		__int8 _thirdValue;
		__int8 _fourthValue;
		__int8 _fifthValue;
		__int8 _sixthValue;
		__int8 _seventhValue;
		__int8 _eighthValue;

	public:

		EightByteSizeValue(__int64 firstValue) : _firstValue((__int8)firstValue), _secondValue((__int8)(firstValue >> 0x8I64)), _thirdValue((__int8)(firstValue >> 0x10I64)), _fourthValue((__int8)(firstValue >> 0x18I64)), _fifthValue((__int8)(firstValue >> 0x20I64)), _sixthValue((__int8)(firstValue >> 0x28I64)), _seventhValue((__int8)(firstValue >> 0x30I64)), _eighthValue((__int8)(firstValue >> 0x38I64)) { }
	};
	class SevenByteSizeValue
	{
		__int8 _firstValue;
		__int8 _secondValue;
		__int8 _thirdValue;
		__int8 _fourthValue;
		__int8 _fifthValue;
		__int8 _sixthValue;
		__int8 _seventhValue;

	public:

		SevenByteSizeValue(__int64 firstValue) : _firstValue((__int8)firstValue), _secondValue((__int8)(firstValue >> 0x8I64)), _thirdValue((__int8)(firstValue >> 0x10I64)), _fourthValue((__int8)(firstValue >> 0x18I64)), _fifthValue((__int8)(firstValue >> 0x20I64)), _sixthValue((__int8)(firstValue >> 0x28I64)), _seventhValue((__int8)(firstValue >> 0x30I64)) { }
	};
	class SixByteSizeValue
	{
		__int8 _firstValue;
		__int8 _secondValue;
		__int8 _thirdValue;
		__int8 _fourthValue;
		__int8 _fifthValue;
		__int8 _sixthValue;

	public:

		SixByteSizeValue(__int64 firstValue) : _firstValue((__int8)firstValue), _secondValue((__int8)(firstValue >> 0x8I64)), _thirdValue((__int8)(firstValue >> 0x10I64)), _fourthValue((__int8)(firstValue >> 0x18I64)), _fifthValue((__int8)(firstValue >> 0x20I64)), _sixthValue((__int8)(firstValue >> 0x28I64)) { }
	};
	class FiveByteSizeValue
	{
		__int8 _firstValue;
		__int8 _secondValue;
		__int8 _thirdValue;
		__int8 _fourthValue;
		__int8 _fifthValue;

	public:

		FiveByteSizeValue(__int64 firstValue) : _firstValue((__int8)firstValue), _secondValue((__int8)(firstValue >> 0x8I64)), _thirdValue((__int8)(firstValue >> 0x10I64)), _fourthValue((__int8)(firstValue >> 0x18I64)), _fifthValue((__int8)(firstValue >> 0x20I64)) { }
	};
	class FourByteSizeValue
	{
		__int8 _firstValue;
		__int8 _secondValue;
		__int8 _thirdValue;
		__int8 _fourthValue;

	public:

		FourByteSizeValue(__int64 firstValue) : _firstValue((__int8)firstValue), _secondValue((__int8)(firstValue >> 0x8I64)), _thirdValue((__int8)(firstValue >> 0x10I64)), _fourthValue((__int8)(firstValue >> 0x18I64)) { }
	};
	class ThreeByteSizeValue
	{
		__int8 _firstValue;
		__int8 _secondValue;
		__int8 _thirdValue;

	public:

		ThreeByteSizeValue(__int64 firstValue) : _firstValue((__int8)firstValue), _secondValue((__int8)(firstValue >> 0x8I64)), _thirdValue((__int8)(firstValue >> 0x10I64)) { }
	};
	class TwoByteSizeValue
	{
		__int8 _firstValue;
		__int8 _secondValue;

	public:

		TwoByteSizeValue(__int64 firstValue) : _firstValue((__int8)firstValue), _secondValue((__int8)(firstValue >> 0x8I64)) { }
	};
	class OneByteSizeValue
	{
		__int8 _firstValue;

	public:

		OneByteSizeValue(__int64 firstValue) : _firstValue((__int8)firstValue) { }
	};

	if (GetSimplifiedValue(SixteenByteSizeValue(0x123456789ABCDEF7I64, 0x7FEDCBA987654321I64)) != 0x6DD99DD11DD99DD6I64)
		return 0x1I64;
	if (GetSimplifiedValue(FifteenByteSizeValue(0x123456789ABCDEF7I64, 0x7FEDCBA987654321I64)) != 0x12D99DD11DD99DD6I64)
		return 0x2I64;
	if (GetSimplifiedValue(FourteenByteSizeValue(0x123456789ABCDEF7I64, 0x7FEDCBA987654321I64)) != 0x12349DD11DD99DD6I64)
		return 0x3I64;
	if (GetSimplifiedValue(ThirteenByteSizeValue(0x123456789ABCDEF7I64, 0x7FEDCBA987654321I64)) != 0x123456D11DD99DD6I64)
		return 0x4I64;
	if (GetSimplifiedValue(TwelveByteSizeValue(0x123456789ABCDEF7I64, 0x7FEDCBA987654321I64)) != 0x123456781DD99DD6I64)
		return 0x5I64;
	if (GetSimplifiedValue(ElevenByteSizeValue(0x123456789ABCDEF7I64, 0x7FEDCBA987654321I64)) != 0x123456789AD99DD6I64)
		return 0x6I64;
	if (GetSimplifiedValue(TenByteSizeValue(0x123456789ABCDEF7I64, 0x7FEDCBA987654321I64)) != 0x123456789ABC9DD6I64)
		return 0x7I64;
	if (GetSimplifiedValue(NineByteSizeValue(0x123456789ABCDEF7I64, 0x7FEDCBA987654321I64)) != 0x123456789ABCDED6I64)
		return 0x8I64;
	if (GetSimplifiedValue(EightByteSizeValue(0x123456789ABCDEF7I64)) != 0x123456789ABCDEF7I64)
		return 0x9I64;
	if (GetSimplifiedValue(SevenByteSizeValue(0x123456789ABCDEF7I64)) != 0x3456789ABCDEF7I64)
		return 0xAI64;
	if (GetSimplifiedValue(SixByteSizeValue(0x123456789ABCDEF7I64)) != 0x56789ABCDEF7I64)
		return 0xBI64;
	if (GetSimplifiedValue(FiveByteSizeValue(0x123456789ABCDEF7I64)) != 0x789ABCDEF7I64)
		return 0xCI64;
	if (GetSimplifiedValue(FourByteSizeValue(0x123456789ABCDEF7I64)) != 0x9ABCDEF7I64)
		return 0xDI64;
	if (GetSimplifiedValue(ThreeByteSizeValue(0x123456789ABCDEF7I64)) != 0xBCDEF7I64)
		return 0xEI64;
	if (GetSimplifiedValue(TwoByteSizeValue(0x123456789ABCDEF7I64)) != 0xDEF7I64)
		return 0xFI64;
	if (GetSimplifiedValue(OneByteSizeValue(0x123456789ABCDEF7I64)) != 0xF7I64)
		return 0x10I64;
	return 0x0I64;
}
__int64 const StaticStorageTest()
{
	__int64 constexpr testCount = 0x100I64;

	class Data
	{
		StaticStorage<__int64, testCount>* _storage;

	public:

		Data() : _storage(new StaticStorage<__int64, testCount>) { }
		~Data()
		{
			delete _storage;
		}
		StaticStorage<__int64, testCount>& GetStorage()
		{
			return *_storage;
		}
	};
	Data data = { };
	for (__int64 offset = 0x0I64; offset != testCount; offset++)
	{
		if (data.GetStorage().GetCapacity() != testCount)
			return _integerMaxUnsigned;
		data.GetStorage()[offset] = offset;
		for (__int64 checkingOffset = 0x0I64; checkingOffset <= offset; checkingOffset++)
			if (data.GetStorage()[checkingOffset] != checkingOffset)
				return 0x1I64 + checkingOffset;
	}
	return 0x0I64;
}
__int64 const DynamicStorageTest()
{
	__int64 constexpr testCount = 0x100I64;

	class Data
	{
		DynamicStorage<__int64>* _storage;

	public:

		Data() : _storage(new DynamicStorage<__int64>(0x0I64)) { }
		~Data()
		{
			delete _storage;
		}
		DynamicStorage<__int64>& GetStorage()
		{
			return *_storage;
		}
	};

	Data data = { };
	if (data.GetStorage().GetCapacity() != 0x0I64)
		return _integerMaxUnsigned;
	for (__int64 offset = 0x0I64; offset != testCount; offset++)
	{
		__int64 const enoughCapacity = GetEnoughCapacity(data.GetStorage().GetCapacity(), offset + 0x1I64);
		if (enoughCapacity != data.GetStorage().GetCapacity())
			data.GetStorage().SetCapacity(enoughCapacity);
		if (data.GetStorage().GetCapacity() != enoughCapacity)
			return _integerMaxUnsigned - 0x1I64;
		data.GetStorage()[offset] = offset;
		for (__int64 checkingOffset = 0x0I64; checkingOffset != offset; checkingOffset++)
			if (data.GetStorage()[checkingOffset] != checkingOffset)
				return 0x1I64 + checkingOffset;
	}
	return 0x0I64;
}
__int32 main()
{
	if (GetSimplifiedValueTest() != 0x0I64)
		return 0x1I64;
	if (StaticStorageTest() != 0x0I64)
		return 0x1I64;
	if (DynamicStorageTest() != 0x0I64)
		return 0x1I64;
	constexpr __int64 count = 0x10000000I64;
	__int64* stackPointer = new __int64[count];
	__int64 firstValue = PseudoRandomManager::GetInt64Remainder(5I64);
	__int64 writeOffset = 0x1I64;
	__int64 readOffset = 0x1I64;
	while (writeOffset != count)
	{
		__int64 value;
		value = stackPointer[writeOffset++] = PseudoRandomManager::GetInt64Remainder(5I64);
		for (; readOffset != writeOffset; readOffset++)
		{
			if (stackPointer[readOffset] != firstValue)
				continue;
			__int64 roof = readOffset + readOffset;
			if (roof > count)
				throw new std::exception();
			while (writeOffset != roof)
				value = stackPointer[writeOffset++] = PseudoRandomManager::GetInt64Remainder(5I64);
			bool isLap = true;
			for (__int64 leftOffset = 0x1I64, rightOffset = readOffset + 0x1I64; leftOffset != readOffset; leftOffset++, rightOffset++)
			{
				__int64 leftValue = stackPointer[leftOffset];
				__int64 rightValue = stackPointer[rightOffset];
				if (leftValue != rightValue)
				{
					isLap = false;
					break;
				}
			}
			if (isLap)
				throw new std::exception();
		}
	}
}