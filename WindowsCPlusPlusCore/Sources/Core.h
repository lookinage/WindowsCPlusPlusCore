#pragma once

#include <cstdlib>
#include <string>

namespace Core
{
	__int64 constexpr _integerMin = 0x8000000000000000I64;
	__int64 constexpr _integerMaxSigned = 0x7FFFFFFFFFFFFFFFI64;
	__int64 constexpr _integerMaxUnsigned = 0xFFFFFFFFFFFFFFFFI64;

	template<typename T>
	__int64 GetSimplifiedValue(T const& reference)
	{
		__int8 const* pointer = (__int8*)&reference;
		__int64 result = *(__int64 const*)pointer;
		auto sizes = std::lldiv(sizeof(T), sizeof(__int64));
		sizes.quot *= sizeof(__int64);
		for (__int64 offset = sizeof(__int64); offset != sizes.quot; offset += sizeof(__int64))
			result ^= *(__int64*)(pointer + offset);
		if (sizes.rem == 0x0I64)
			return result;
		if (sizes.rem == sizeof(__int32) + sizeof(__int16) + sizeof(__int8))
		{
			pointer += sizes.quot - 0x1I64;
			*(__int32*)&result ^= *(__int32*)pointer;
			*(__int16*)((__int8*)&result + sizeof(__int32)) ^= *(__int16*)(pointer + sizeof(__int32));
			*(__int8*)((__int8*)&result + sizeof(__int32) + sizeof(__int16)) ^= *(__int8*)(pointer + sizeof(__int32) + sizeof(__int16));
			return result;
		}
		if (sizes.rem == sizeof(__int32) + sizeof(__int16))
		{
			pointer += sizes.quot - 0x1I64;
			*(__int32*)&result ^= *(__int32*)pointer;
			*(__int16*)((__int8*)&result + sizeof(__int32)) ^= *(__int16*)(pointer + sizeof(__int32));
			return result;
		}
		if (sizes.rem == sizeof(__int32) + sizeof(__int8))
		{
			pointer += sizes.quot - 0x1I64;
			*(__int32*)&result ^= *(__int32*)pointer;
			*(__int8*)((__int8*)&result + sizeof(__int32)) ^= *(__int8*)(pointer + sizeof(__int32));
			return result;
		}
		if (sizes.rem == sizeof(__int32))
		{
			*(__int32*)&result ^= *(__int32*)(pointer + sizes.quot - 0x1I64);
			return result;
		}
		if (sizes.rem == sizeof(__int16) + sizeof(__int8))
		{
			pointer += sizes.quot - 0x1I64;
			*(__int16*)&result ^= *(__int16*)pointer;
			*(__int8*)((__int8*)&result + sizeof(__int16)) ^= *(__int8*)(pointer + sizeof(__int16));
			return result;
		}
		if (sizes.rem == sizeof(__int16))
		{
			*(__int16*)&result ^= *(__int16*)(pointer + sizes.quot - 0x1I64);
			return result;
		}
		if (sizes.rem == sizeof(__int8))
		{
			*(__int8*)&result ^= *(__int8*)(pointer + sizes.quot - 0x1I64);
			return result;
		}
	}
	__int64 GetEnoughCapacity(__int64 const capacity, __int64 const count);

	template<typename T, __int64 Capacity>
	struct StaticStorage
	{
		T _elements[Capacity];

	public:

		StaticStorage() : _elements() { }

		const __int64 GetCapacity() const
		{
			return Capacity;
		}

		T& operator[](__int64 const offset)
		{
			return _elements[offset];
		}
	};
	template<typename T, __int64 Capacity>
	bool operator==(StaticStorage<T, Capacity> const& left, StaticStorage<T, Capacity> const& right)
	{
		return memcmp(&left, &right, sizeof(T) * Capacity) == 0x0I32;
	};
	template<typename T, __int64 Capacity>
	bool operator!=(StaticStorage<T, Capacity> const& left, StaticStorage<T, Capacity> const& right)
	{
		return memcmp(&left, &right, sizeof(T) * Capacity) != 0x0I32;
	};

	template<typename T>
	class DynamicStorage
	{
		template<typename T>
		friend bool operator==(DynamicStorage<T> const& left, DynamicStorage<T> const& right);
		template<typename T>
		friend bool operator!=(DynamicStorage<T> const& left, DynamicStorage<T> const& right);

		__int64 _capacity;
		T* _elements;

	public:

		explicit DynamicStorage(const __int64 capacity) : _capacity(capacity), _elements(new T[capacity]) { }
		~DynamicStorage()
		{
			delete _elements;
		}

		__int64 GetCapacity() const
		{
			return _capacity;
		}
		void SetCapacity(__int64 const capacity)
		{
			T* elements = new T[capacity];
			memcpy(elements, _elements, _capacity * sizeof(T));
			_capacity = capacity;
			delete _elements;
			_elements = elements;
			return;
		}

		T& operator[](__int64 const offset) const
		{
			return _elements[offset];
		}
	};
	template<typename T>
	bool operator==(DynamicStorage<T> const& left, DynamicStorage<T> const& right)
	{
		return left._elements == right._elements;
	};
	template<typename T>
	bool operator!=(DynamicStorage<T> const& left, DynamicStorage<T> const& right)
	{
		return left._elements != right._elements;
	};

	template<typename T>
	class StandingStack
	{
		DynamicStorage<T> _storage;
		__int64 _count;

	public:

		class AscendingEnumerator
		{
			friend class StandingStack;

			StandingStack const& _stack;
			__int64 const _edge;
			__int64 _offset;

			explicit AscendingEnumerator(StandingStack const& stack, __int64 const edge, __int64 const offset) : _stack(stack), _edge(edge), _offset(offset) { }

		public:

			bool operator!() const
			{
				return _offset != _edge;
			}
			T const& operator*() const
			{
				return _stack._storage[_offset];
			}
			AscendingEnumerator& operator++()
			{
				_offset++;
				return *this;
			}
		};
		class DescendingEnumerator
		{
			friend class StandingStack;

			StandingStack const& _stack;
			__int64 const _edge;
			__int64 _offset;

			explicit DescendingEnumerator(StandingStack const& stack, __int64 const edge, __int64 const offset) : _stack(stack), _edge(edge), _offset(offset) { }

		public:

			bool operator!() const
			{
				return _offset != _edge;
			}
			T const& operator*() const
			{
				return _stack._storage[_offset];
			}
			DescendingEnumerator& operator++()
			{
				_offset--;
				return *this;
			}
		};

		explicit StandingStack(__int64 const capacity) : _storage(capacity), _count(0x0I64) { }

		__int64 GetCount() const { return _count; }
		T GetAt(__int64 const offset) const { return _storage[offset]; }
		AscendingEnumerator GetAscendingEnumerator(__int64 const offset, __int64 const edge) const
		{
			return AscendingEnumerator(*this, edge, offset);
		}
		AscendingEnumerator GetAscendingEnumerator() const
		{
			return GetAscendingEnumerator(0x0I64, _count);
		}
		DescendingEnumerator GetDescendingEnumerator(__int64 const offset, __int64 const edge) const
		{
			return DescendingEnumerator(*this, edge, offset);
		}
		DescendingEnumerator GetDescendingEnumerator() const
		{
			return GetDescendingEnumerator(_count - 0x1I64, -0x1I64);
		}
		bool TryAdd(T const value)
		{
			__int64 offset;

			if ((offset = _count++) != _integerMaxUnsigned)
			{
				if (_count <= _storage.GetCapacity())
				{
				Adding:
					_storage[offset] = value;
					return true;
				}
				_storage.SetCapacity(GetEnoughCapacity
				(
					_storage.GetCapacity(),
					_count
				));
				goto Adding;
			}
			_count--;
			return false;
		}
		void Set(__int64 const offset, T const value) { _storage[offset] = value; }
		bool TryRemove(T& value)
		{
			if (_count != 0x0I64)
			{
				value = _storage[--_count];
				return true;
			}
			return false;
		}
		void Clear() { _count = 0x0I64; }
	};

	template<typename T>
	class LyingStack
	{
		T* _elements;
		__int64 _capacity;
		__int64 _startOffset;
		__int64 _endOffset;
		__int64 _count;

		inline __int64 GetActualOffset(__int64 const offset) const
		{
			__int64 const actualOffset = _startOffset + offset;
			return actualOffset < _capacity ? actualOffset : actualOffset - _capacity;
		}
		inline void IncreaseCapacity()
		{
			__int64	capacity = GetEnoughCapacity(_capacity, _count);
			__int64	offset = (capacity - _capacity) >> 0x1I64;
			T* elements = new T[capacity];
			if (_startOffset != 0x0I64)
			{
				memcpy(elements + offset, _elements + _startOffset, (_capacity - _startOffset) * sizeof(T));
				memcpy(elements + offset + _capacity - _startOffset, _elements, (_startOffset) * sizeof(T));
			}
			else
				memcpy(elements + offset, _elements, _capacity * sizeof(T));
			delete _elements;
			_elements = elements;
			_capacity = capacity;
			_startOffset = offset;
			_endOffset = offset + _count - 0x1I64;
			return;
		}

	public:

		class AscendingEnumerator
		{
			friend class LyingStack;

			LyingStack const& _stack;
			__int64 const _edge;
			__int64 _offset;

			explicit AscendingEnumerator(LyingStack const& stack, __int64 const edge, __int64 const offset) : _stack(stack), _edge(edge), _offset(offset) { }

		public:

			bool operator!() const
			{
				return _offset != _edge;
			}
			T const& operator*() const
			{
				return _stack._elements[_offset];
			}
			AscendingEnumerator& operator++()
			{
				if (++_offset == _stack._capacity)
					_offset = 0x0I64;
				return *this;
			}
		};
		class DescendingEnumerator
		{
			friend class LyingStack;

			LyingStack const& _stack;
			__int64 const _edge;
			__int64 _offset;

			explicit DescendingEnumerator(LyingStack const& stack, __int64 const edge, __int64 const offset) : _stack(stack), _edge(edge), _offset(offset) { }

		public:

			bool operator!() const
			{
				return _offset != _edge;
			}
			T const& operator*() const
			{
				return _stack._elements[_offset];
			}
			DescendingEnumerator& operator++()
			{
				if (--_offset < 0x0I64)
					_offset = _stack._capacity - 0x1I64;
				return *this;
			}
		};

		explicit LyingStack(__int64 const capacity) : _elements(new T[capacity]), _capacity(capacity), _startOffset(0x0I64), _endOffset(0x0I64), _count(0x0I64) { }
		~LyingStack() { delete _elements; }

		__int64 GetCount() const { return _count; }
		T GetAt(__int64 const offset) const { return _elements[GetActualOffset(offset)]; }
		AscendingEnumerator GetAscendingEnumerator(__int64 const edge, __int64 const offset) const
		{
			return AscendingEnumerator(*this, GetActualOffset(edge), GetActualOffset(offset));
		}
		AscendingEnumerator GetAscendingEnumerator() const
		{
			return GetAscendingEnumerator(_count, 0x0I64);
		}
		DescendingEnumerator GetDescendingEnumerator(__int64 const edge, __int64 const offset) const
		{
			return DescendingEnumerator(*this, GetActualOffset(edge == -0x1I64 ? _capacity - 0x1I64 : edge), GetActualOffset(offset));
		}
		DescendingEnumerator GetDescendingEnumerator() const
		{
			return GetDescendingEnumerator(-0x1I64, _count - 0x1I64);
		}
		bool TryAddLast(T const value)
		{
			if (_count++ != _integerMaxUnsigned)
			{
				if (_count <= _capacity)
				{
				Setting:
					_elements[_endOffset++] = value;
					if (_endOffset == _capacity)
						_endOffset = 0x0I64;
					return true;
				}
				IncreaseCapacity();
				goto Setting;
			}
			_count--;
			return false;
		}
		bool TryAddFirst(T const value)
		{
			if (_count++ != _integerMaxUnsigned)
			{
				if (_count <= _capacity)
				{
				CheckingOffset:
					if (--_startOffset >= 0x0I64)
					{
					Setting:
						_elements[_startOffset] = value;
						return true;
					}
					_startOffset = _capacity - 0x1I64;
					goto Setting;
				}
				IncreaseCapacity();
				goto CheckingOffset;
			}
			_count--;
			return false;
		}
		void Set(__int64 const offset, T const value) { _elements[GetActualOffset(offset)] = value; }
		bool TryRemoveLast(T& value)
		{
			if (_count-- != 0x0I64)
			{
				if (--_endOffset >= 0x0I64)
				{
				Setting:
					value = _elements[_endOffset];
					return true;
				}
				_endOffset = _capacity - 0x1I64;
				goto Setting;
			}
			_count++;
			return false;
		}
		bool TryRemoveFirst(T& value)
		{
			if (_count-- != 0x0I64)
			{
				value = _elements[_startOffset];
				if (++_startOffset != _capacity)
					return true;
				_startOffset = 0x0I64;
				return true;
			}
			_count++;
			return false;
		}
		void Clear()
		{
			_startOffset = _endOffset = _capacity >> 0x1I64;
			_count = 0x0I64;
		}
	};

	template<typename T>
	class Subset
	{
		class Element
		{
			friend class Subset;

			__int64 _nextElementOffset;
			__int64 _simplifiedValue;
			T _value;
		};

		DynamicStorage<Element> _storage;
		__int64* _chainStartOffsets;
		__int64 _freeElementOffset;
		__int64 _usedElementCount;
		__int64 _count;

		inline void IncreaseCapacity(__int64 const capacity)
		{
			__int64	previousCapacity = _storage.GetCapacity();
			_storage.SetCapacity(capacity);
			delete _chainStartOffsets;
			_chainStartOffsets = new __int64[capacity];
			memset(_chainStartOffsets, 0x0I32, _storage.GetCapacity() * sizeof(__int64));
			for (__int64 elementOffset = 0x0I64; elementOffset != previousCapacity; elementOffset++)
			{
				__int64 chainOffset = _storage[elementOffset]._simplifiedValue % capacity;
				_storage[elementOffset]._nextElementOffset = _chainStartOffsets[chainOffset] - 0x1I64;
				_chainStartOffsets[chainOffset] = elementOffset + 0x1I64;
			}
		}
		inline bool TryRemove(T const value, __int64 const simplifiedValue)
		{
			__int64 const chainOffset = simplifiedValue % _storage.GetCapacity();
			for (__int64 elementOffset = _chainStartOffsets[chainOffset] - 0x1I64, lastElementOffset = -0x1I64; elementOffset != -0x1I64; lastElementOffset = elementOffset, elementOffset = _storage[elementOffset]._nextElementOffset)
			{
				if (value != _storage[elementOffset]._value)
					continue;
				if (lastElementOffset == -0x1I64)
					_chainStartOffsets[chainOffset] = _storage[elementOffset]._nextElementOffset + 0x1I64;
				else
					_storage[lastElementOffset]._nextElementOffset = _storage[elementOffset]._nextElementOffset;
				_storage[elementOffset]._nextElementOffset = _freeElementOffset;
				_storage[elementOffset]._simplifiedValue = -0x1I64;
				_freeElementOffset = elementOffset;
				_count--;
				return true;
			}
			return false;
		}

	public:

		class Enumerator
		{
			friend class Subset;

			Subset<T> const& _subset;
			__int64 _offset;
			bool _canContinue;

			explicit Enumerator(Subset<T> const& subset) : _subset(subset), _offset(0x0I64), _canContinue(true)
			{
				SetValid();
			}

			void SetValid()
			{
				for (; ; _offset++)
				{
					if (_offset != _subset._usedElementCount)
					{
						if (_subset._storage[_offset]._simplifiedValue != -0x1I64)
							break;
						continue;
					}
					_canContinue = false;
					break;
				}
			}

		public:

			bool operator!() const
			{
				return _canContinue;
			}
			T const& operator*() const
			{
				return _subset._storage[_offset]._value;
			}
			Enumerator& operator++()
			{
				_offset++;
				SetValid();
				return *this;
			}
		};

		Subset(__int64 const capacity) : _storage(capacity), _chainStartOffsets(new __int64[capacity]), _freeElementOffset(-0x1I64), _usedElementCount(0x0I64), _count(0x0I64) { }
		~Subset()
		{
			delete _chainStartOffsets;
		}

		__int64 GetCount() const
		{
			return _count;
		}
		bool TryGetAddress(T const value, __int64& address) const
		{
			for (__int64 elementOffset = _chainStartOffsets[GetSimplifiedValue(value) % _storage.GetCapacity()] - 0x1I64; elementOffset != -0x1I64; elementOffset = _storage[elementOffset]._nextElementOffset)
			{
				if (value != _storage[elementOffset]._value)
					continue;
				address = elementOffset;
				return true;
			}
			return false;
		}
		bool ContainsAt(__int64 const address) const { return address >= 0x0I64 && address < _usedElementCount&& _storage[address]._simplifiedValue != -0x1I64; }
		bool TryGetAt(__int64 const address, T& value) const
		{
			if (address < 0x0I64 || address >= _usedElementCount || _storage[address]._simplifiedValue == -0x1I64)
				return false;
			value = _storage[address]._value;
			return true;
		}
		Enumerator GetEnumerator() const
		{
			return Enumerator(*this);
		}
		bool TryAdd(T const value, __int64& address)
		{
			if (_count++ == _integerMaxUnsigned)
			{
				_count--;
				return false;
			}
			if (_count > _storage.GetCapacity())
				IncreaseCapacity(GetEnoughCapacity(_storage.GetCapacity(), _count));
			__int64	const simplifiedValue = GetSimplifiedValue(value);
			__int64 const chainOffset = simplifiedValue % _storage.GetCapacity();
			__int64 elementOffset;
			for (elementOffset = _chainStartOffsets[chainOffset] - 0x1I64; elementOffset != -0x1I64; elementOffset = _storage[elementOffset]._nextElementOffset)
			{
				if (value != _storage[elementOffset]._value)
					continue;
				_count--;
				return false;
			}
			if (_freeElementOffset != -0x1I64)
			{
				elementOffset = _freeElementOffset;
				_freeElementOffset = _storage[elementOffset]._nextElementOffset;
			}
			else
				elementOffset = _usedElementCount++;
			_storage[elementOffset]._nextElementOffset = _chainStartOffsets[chainOffset] - 0x1I64;
			_storage[elementOffset]._simplifiedValue = simplifiedValue;
			_storage[elementOffset]._value = value;
			_chainStartOffsets[chainOffset] = elementOffset + 0x1I64;
			address = elementOffset;
			return true;
		}
		bool TryRemove(T const value)
		{
			return TryRemove(value, GetSimplifiedValue(value));
		}
		bool TryRemoveAt(__int64 const address, T& value)
		{
			__int64 const simplifiedValue = _storage[address]._simplifiedValue;
			if (address < 0x0I64 || address >= _usedElementCount || simplifiedValue == -0x1I64)
				return false;
			value = _storage[address]._value;
			return TryRemove(value, simplifiedValue);
		}
		void Clear()
		{
			memset(_chainStartOffsets, 0x0I32, _storage.GetCapacity() * sizeof(__int64));
			_freeElementOffset = -0x1I64;
			_usedElementCount = 0x0I64;
			_count = 0x0I64;
		}
	};

	template<typename TInput, typename TOutput>
	class Relation
	{
		TInput _input;
		TOutput _output;

	public:

		Relation() : _input(), _output() { }
		Relation(TInput const input, TOutput const output) : _input(input), _output(output) { }

		TInput GetInput() const
		{
			return _input;
		}
		TOutput GetOutput() const
		{
			return _output;
		}
		void SetInput(TInput const& input)
		{
			_input = input;
		}
		void SetOutput(TInput const& output)
		{
			_output = output;
		}
	};

	template<typename TInput, typename TOutput>
	class Surjection
	{
		class Element
		{
			friend class Surjection;

			__int64 _nextElementOffset;
			__int64 _simplifiedInput;
			Relation<TInput, TOutput> _relation;
		};

		DynamicStorage<Element> _storage;
		__int64* _chainStartOffsets;
		__int64 _freeElementOffset;
		__int64 _usedElementCount;
		__int64 _count;

		inline void IncreaseCapacity(__int64 capacity)
		{
			__int64 const previousCapacity = _storage.GetCapacity();
			_storage.SetCapacity(capacity);
			delete _chainStartOffsets;
			_chainStartOffsets = new __int64[capacity];
			memset(_chainStartOffsets, 0x0I32, _storage.GetCapacity() * sizeof(__int64));
			for (__int64 elementOffset = 0x0I64; elementOffset != previousCapacity; elementOffset++)
			{
				__int64 chainOffset = _storage[elementOffset]._simplifiedInput % capacity;
				_storage[elementOffset]._nextElementOffset = _chainStartOffsets[chainOffset] - 0x1I64;
				_chainStartOffsets[chainOffset] = elementOffset + 0x1I64;
			}
		}
		inline bool TryRemove(TInput const input, __int64 const _simplifiedValue)
		{
			__int64 const chainOffset = _simplifiedValue % _storage.GetCapacity();
			for (__int64 elementOffset = _chainStartOffsets[chainOffset] - 0x1I64, lastElementOffset = -0x1I64; elementOffset != -0x1I64; lastElementOffset = elementOffset, elementOffset = _storage[elementOffset]._nextElementOffset)
			{
				if (input != _storage[elementOffset]._relation.GetInput())
					continue;
				if (lastElementOffset == -0x1I64)
					_chainStartOffsets[chainOffset] = _storage[elementOffset]._nextElementOffset + 0x1I64;
				else
					_storage[lastElementOffset]._nextElementOffset = _storage[elementOffset]._nextElementOffset;
				_storage[elementOffset]._nextElementOffset = _freeElementOffset;
				_storage[elementOffset]._simplifiedInput = -0x1I64;
				_freeElementOffset = elementOffset;
				_count--;
				return true;
			}
			return false;
		}

	public:

		class Enumerator
		{
			friend class Surjection;

			Surjection<TInput, TOutput> const& _surjection;
			__int64 _offset;
			bool _canContinue;

			explicit Enumerator(Surjection<TInput, TOutput> const& surjection) : _surjection(surjection), _offset(0x0I64), _canContinue(true)
			{
				SetValid();
			}

			void SetValid()
			{
				for (; ; _offset++)
				{
					if (_offset != _surjection._usedElementCount)
					{
						if (_surjection._storage[_offset]._simplifiedInput != -0x1I64)
							break;
						continue;
					}
					_canContinue = false;
					break;
				}
			}

		public:

			bool operator!() const
			{
				return _canContinue;
			}
			Relation<TInput, TOutput> const& operator*() const
			{
				return _surjection._storage[_offset]._relation;
			}
			Enumerator& operator++()
			{
				_offset++;
				SetValid();
				return *this;
			}
		};

		Surjection(__int64 const capacity) : _storage(capacity), _chainStartOffsets(new __int64[capacity]), _freeElementOffset(-0x1I64), _usedElementCount(0x0I64), _count(0x0I64) { }
		~Surjection()
		{
			delete _chainStartOffsets;
		}

		__int64 GetCount() const
		{
			return _count;
		}
		bool TryGetAddress(TInput const input, __int64& address) const
		{
			for (__int64 elementOffset = _chainStartOffsets[GetSimplifiedValue(input) % _storage.GetCapacity()] - 0x1I64; elementOffset != -0x1I64; elementOffset = _storage[elementOffset]._nextElementOffset)
			{
				if (input != _storage[elementOffset]._relation.GetInput())
					continue;
				address = elementOffset;
				return true;
			}
			return false;
		}
		bool ContainsAt(__int64 const address) const
		{
			return address >= 0x0I64 && address < _usedElementCount&& _storage[address]._simplifiedInput != -0x1I64;
		}
		bool TryGetAt(__int64 const address, Relation<TInput, TOutput>& relation) const
		{
			if (address < 0x0I64 || address >= _usedElementCount || _storage[address]._simplifiedInput == -0x1I64)
				return false;
			relation = _storage[address]._relation;
			return true;
		}
		Enumerator GetEnumerator() const
		{
			return Enumerator(*this);
		}
		bool TryAdd(Relation<TInput, TOutput> const relation, __int64& address)
		{
			if (_count++ == _integerMaxUnsigned)
			{
				_count--;
				return false;
			}
			if (_count > _storage.GetCapacity())
				IncreaseCapacity(GetEnoughCapacity(_storage.GetCapacity(), _count));
			__int64 const simplifiedInput = GetSimplifiedValue(relation.GetInput());
			__int64 const chainOffset = simplifiedInput % _storage.GetCapacity();
			__int64 elementOffset;
			for (elementOffset = _chainStartOffsets[chainOffset] - 0x1I64; elementOffset != -0x1I64; elementOffset = _storage[elementOffset]._nextElementOffset)
			{
				if (relation.GetInput() != _storage[elementOffset]._relation.GetInput())
					continue;
				_count--;
				return false;
			}
			if (_freeElementOffset != -0x1I64)
			{
				elementOffset = _freeElementOffset;
				_freeElementOffset = _storage[elementOffset]._nextElementOffset;
			}
			else
				elementOffset = _usedElementCount++;
			_storage[elementOffset]._nextElementOffset = _chainStartOffsets[chainOffset] - 0x1I64;
			_storage[elementOffset]._simplifiedInput = simplifiedInput;
			_storage[elementOffset]._relation = relation;
			_chainStartOffsets[chainOffset] = elementOffset + 0x1I64;
			address = elementOffset;
			return true;
		}
		bool TryRemove(TInput const input)
		{
			return TryRemove(input, GetSimplifiedValue(input));
		}
		bool TryRemoveAt(__int64 const address, Relation<TInput, TOutput>& relation)
		{
			__int64 const simplifiedInput = _storage[address]._simplifiedInput;
			if (address < 0x0I64 || address >= _usedElementCount || simplifiedInput == -0x1I64)
				return false;
			relation = _storage[address]._relation;
			return TryRemove(relation.GetInput(), simplifiedInput);
		}
		void Clear()
		{
			memset(_chainStartOffsets, 0x0I32, _storage.GetCapacity() * sizeof(__int64));
			_freeElementOffset = -0x1I64;
			_usedElementCount = 0x0I64;
			_count = 0x0I64;
		}
	};
}