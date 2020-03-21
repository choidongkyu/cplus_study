#pragma once
#include <queue>
#include <memory>
namespace lab9
{
	template<typename T>
	class ObjectPool final
	{
	public:
		ObjectPool(size_t maxPoolSize);
		ObjectPool(ObjectPool& rhs) = delete;
		ObjectPool& operator=(const ObjectPool& rhs) = delete;
		~ObjectPool();
		T* Get();
		void Return(T* object);
		const size_t GetFreeObjectCount() const;
		const size_t GetMaxFreeObjectCount() const;

	private:
		size_t mMaxPoolSize;
		std::queue<T*> mObjectPool;
	};

	template<typename T>
	inline ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
	{
	}


	template<typename T>
	inline ObjectPool<T>::~ObjectPool()
	{
		while (mObjectPool.size() != 0)
		{
			delete mObjectPool.front();
			mObjectPool.pop();
		}
	}

	template<typename T>
	inline T* ObjectPool<T>::Get()
	{
		T* object;
		if (mObjectPool.size() != 0)
		{
			object = mObjectPool.front();
			mObjectPool.pop();
			return object;
		}

		return new T();
		// TODO: 여기에 return 문을 삽입합니다.
	}

	template<typename T>
	inline void ObjectPool<T>::Return(T* object)
	{
		if (mObjectPool.size() >= mMaxPoolSize)
		{
			return;
		}
		mObjectPool.push(object);
	}

	template<typename T>
	inline const size_t ObjectPool<T>::GetFreeObjectCount() const
	{
		return mObjectPool.size();
	}

	template<typename T>
	inline const size_t ObjectPool<T>::GetMaxFreeObjectCount() const
	{
		return mMaxPoolSize;
	}
}