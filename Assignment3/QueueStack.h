#include "SmartStack.h"
#include "SmartQueue.h"

namespace assignment3
{
	template <typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		void Enqueue(T data);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();
	private:
		unsigned int mMaxStackSize;
		T mSum;
		SmartStack<T> mStack;
		std::queue<SmartStack<T>> mQueue;
	};

	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
		, mSum(0)
	{
	}

	template<typename T>
	inline void QueueStack<T>::Enqueue(T data)
	{
		mSum += data;
		if (mQueue.empty() || mQueue.back().GetCount() >= mMaxStackSize)
		{
			SmartStack<T> stack; 
			stack.Push(data);
			mQueue.push(stack);
			return;
		}
		mQueue.back().Push(data);
	}

	template<typename T>
	inline T QueueStack<T>::Peek()
	{
		return mQueue.front().Peek();
	}

	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		T value = mQueue.front().Pop();
		if (mQueue.front().GetCount() == 0)
		{
			mQueue.pop();
		}
		return value;
	}

	template<typename T>
	inline T QueueStack<T>::GetMax()
	{
		return T();
	}

	template<typename T>
	inline T QueueStack<T>::GetMin()
	{
		return T();
	}

	template<typename T>
	inline double QueueStack<T>::GetAverage()
	{
		return 0.0;
	}

	template<typename T>
	inline T QueueStack<T>::GetSum()
	{
		return T();
	}

	template<typename T>
	inline unsigned int QueueStack<T>::GetCount()
	{
		return 0;
	}

	template<typename T>
	inline unsigned int QueueStack<T>::GetStackCount()
	{
		return 0;
	}
}