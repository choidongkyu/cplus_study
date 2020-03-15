#pragma once
#include <iostream>
namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		~FixedVector();
		bool Add(const T& data);
		bool Remove(const T& data);
		int GetIndex(const T& data) const;
		size_t GetSize() const;
		size_t GetCapacity() const;
		const T& Get(const unsigned int index) const;
		T& operator[](unsigned int index);
	private:
		size_t mSize;
		T mArray[N];
	};

	template<typename T, size_t N>
	inline FixedVector<T, N>::FixedVector()
		: mSize(0)
		, mArray()
	{
		//mArray = new T[N];
	}

	template<typename T, size_t N>
	inline bool FixedVector<T, N>::Add(const T& data)
	{
		if (mSize >= N)
		{
			return false;
		}
		mArray[mSize] = data;
		++mSize;
		return true;
	}

	template<typename T, size_t N>
	inline FixedVector<T, N>::~FixedVector()
	{
		//delete[] mArray;
	}

	template<typename T, size_t N>
	inline bool FixedVector<T, N>::Remove(const T& data)
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			if (mArray[i] == data)
			{
				for (size_t j = i; j < mSize; ++j)
				{
					mArray[j] = mArray[j + 1];
				}
				mArray[mSize] = NULL;
				--mSize;
				return true;
			}
		}
		return false;
	}

	template<typename T, size_t N>
	inline int FixedVector<T, N>::GetIndex(const T& data) const
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			if (mArray[i] == data)
			{
				return static_cast<int>(i);
			}
		}
		return -1;

	}

	template<typename T, size_t N>
	inline const T& FixedVector<T, N>::Get(unsigned int index) const
	{
		return mArray[index];
	}

	template<typename T, size_t N>
	inline T& FixedVector<T, N>::operator[](unsigned int index)
	{
		return mArray[index];
	}

	template<typename T, size_t N>
	inline size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template<typename T, size_t N>
	inline size_t FixedVector<T, N>::GetCapacity() const
	{
		return N;
	}
}

