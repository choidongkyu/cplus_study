#pragma once

#include <memory>
#include <iostream>
namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(const Storage& other);
		Storage& operator=(const Storage& other);
		Storage(Storage&& other);
		Storage& operator=(Storage&& other);
		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

	private:
		std::unique_ptr<T[]> mArray;
		size_t mSize;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		:mSize(length)
	{
		mArray = std::make_unique<T[]>(length);
		std::memset(mArray.get(), 0, length * sizeof(T));
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		:mSize(length)
	{
		mArray = std::make_unique<T[]>(length);
		for (size_t i = 0; i < length; ++i)
		{
			mArray[i] = initialValue;
		}
	}

	template<typename T>
	Storage<T>::Storage(const Storage& other)
		:mSize(other.mSize)
	{
		mArray = std::make_unique<T[]>(other.mSize);
		/*for (size_t i = 0; i < mSize; ++i)
		{
			mArray[i] = other[i];
		}*/
		std::memcpy(mArray.get(), other.mArray.get(), sizeof(T) * mSize);
	}

	template<typename T>
	Storage<T>::Storage(Storage&& other)
		: mSize(other.mSize)
		, mArray(std::move(other.mArray))
	{
		other.mSize = 0;
		other.mArray = nullptr;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(const Storage& other)
	{
		if (this != &other)
		{
			mArray = nullptr;
			mSize = other.mSize;
			mArray = std::make_unique<T[]>(other.mSize);
			/*for (size_t i = 0; i < mSize; ++i)
			{
				mArray[i] = other.mArray[i];
			}*/
			std::memcpy(mArray.get(), other.mArray.get(), sizeof(T) * mSize);
		}
		return *this;
	}

	template <typename T>
	Storage<T>& Storage<T>::operator=(Storage&& other)
	{
		if (this != &other)
		{
			mArray = nullptr;
			mSize = other.mSize;
			mArray = std::move(other.mArray);
			other.mArray = nullptr;
			other.mSize = 0;
		}
		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index >= mSize)
		{
			return false;
		}
		mArray[index] = data;
		return true;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return std::move(mArray);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mSize;
	}

}