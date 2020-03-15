#pragma once
#include <iostream>
#include <bitset>
#include "FixedVector.h"

namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		~FixedVector() = default;
		bool Add(const bool data);
		bool Remove(const bool data);
		int GetIndex(const bool data) const;
		size_t GetSize() const;
		size_t GetCapacity() const;
		bool Get(const unsigned int index) const;
		bool operator[](const unsigned int index) const;
		size_t GetContainerSize(size_t size) const;
	private:
		size_t mSize;
		int32_t mBoolContainer[(N / 32) + 1];
	};

	template<size_t N>
	inline FixedVector<bool, N>::FixedVector()
		: mSize(0)
	{
		memset(mBoolContainer, 0, sizeof(mBoolContainer));
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Add(const bool data)
	{
		int containerSize;
		if (mSize >= N)
		{
			return false;
		}
		++mSize;
		containerSize = GetContainerSize(mSize);
		mBoolContainer[containerSize] = (mBoolContainer[containerSize] << 1);
		if (data)
		{
			mBoolContainer[containerSize] |= 0x01;
		}
		//std::cout << std::bitset<32>(mBoolContainer[containerSize]) << std::endl;
		return true;
	}


	template<size_t N>
	inline bool FixedVector<bool, N>::Remove(const bool data)
	{
		int containerSize;
		int32_t prevBit = 0;
		int32_t filter = -1;

		for (size_t i = 0; i < mSize; ++i)
		{
			containerSize = GetContainerSize(i + 1);
			if ((mBoolContainer[containerSize] >> (mSize - 1 - i) & 1) == data)
			{
				//std::cout << "return data" << std::endl;
				for (size_t k = 0; k < (mSize - i - 1); ++k)
				{
					prevBit = (prevBit << 1);
					filter = (filter << 1);
					filter |= 0x00;
					if (mBoolContainer[containerSize] >> (mSize - i - k - 2) & 1)
					{
						prevBit |= 0x01;
					}
				}
				mBoolContainer[containerSize] = mBoolContainer[containerSize] >> 1;
				//std::cout << "shift result = " << std::bitset<32>(mBoolContainer[containerSize]) << std::endl;
				//std::cout << "filter = " << std::bitset<32>(filter) << std::endl;
				mBoolContainer[containerSize] &= filter;
				//std::cout << "filter result = " << std::bitset<32>(mBoolContainer[containerSize]) << std::endl;
				//std::cout << "prevBit = " << std::bitset<32>(prevBit) << std::endl;
				mBoolContainer[containerSize] |= prevBit;
				//std::cout << "result = " << std::bitset<32>(mBoolContainer[containerSize]) << std::endl;
				--mSize;
				return true;
			}
			else
			{
				//std::cout << "return false" << std::endl;
			}
		}
		return false;
	}

	template<size_t N>
	inline int FixedVector<bool, N>::GetIndex(const bool data) const
	{
		int containerSize;
		for (size_t i = 0; i < mSize; ++i)
		{
			containerSize = GetContainerSize(i + 1);
			if ((mBoolContainer[containerSize] >> (mSize - 1 - i) & 1) == data)
			{
				return i;
			}
		}
		return -1;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Get(unsigned int index) const
	{
		return mBoolContainer[GetContainerSize(index + 1)] >> (mSize - 1 - index) & 1;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::operator[](const unsigned int index) const
	{
		return Get(index);
	}

	template<size_t N>
	inline size_t FixedVector<bool, N>::GetContainerSize(size_t size) const
	{
		size_t containerSize;
		if (size % 32 == 0)
		{
			containerSize = (size / 32) - 1;
		}
		else
		{
			containerSize = size / 32;
		}
		return containerSize;
	}

	template<size_t N>
	inline size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template<size_t N>
	inline size_t FixedVector<bool, N>::GetCapacity() const
	{
		return N;
	}
}