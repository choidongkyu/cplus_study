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
		void Printf() const;
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
		std::cout << std::bitset<32>(mBoolContainer[containerSize]) << std::endl;
		return true;
	}


	template<size_t N>
	inline bool FixedVector<bool, N>::Remove(const bool data)
	{
		int containerSize;
		for (size_t i = 0; i < mSize; ++i)
		{
			containerSize = GetContainerSize(i);
			if (mBoolContainer[containerSize] & i == data)
			{

			}
		}
		return false;
	}

	template<size_t N>
	inline int FixedVector<bool, N>::GetIndex(const bool data) const
	{
	}


	template<size_t N>
	inline void FixedVector<bool, N>::Printf() const
	{
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Get(unsigned int index) const
	{
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::operator[](const unsigned int index) const
	{
		return true;
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