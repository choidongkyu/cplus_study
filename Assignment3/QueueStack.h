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
		unsigned int mCount;
		T mSum;
		SmartStack<T> mStack;
		std::queue<SmartStack<T>> mQueue;
	};

	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
		, mSum(0)
		, mCount(0)
	{
	}

	template<typename T>
	inline void QueueStack<T>::Enqueue(T data)
	{
		mSum += data;
		++mCount;
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
		mSum -= value;
		--mCount;
		if (mQueue.front().GetCount() == 0)
		{
			mQueue.pop();
		}
		return value;
	}

	template<typename T>
	inline T QueueStack<T>::GetMax()
	{
		T max = std::numeric_limits<T>::lowest();
		std::queue<SmartStack<T>> queue(mQueue);
		while (!queue.empty())
		{
			if (max < queue.front().GetMax())
			{
				max = queue.front().GetMax();
			}
			queue.pop();
		}
		return max;
	}

	template<typename T>
	inline T QueueStack<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();
		std::queue<SmartStack<T>> queue(mQueue);
		while (!queue.empty())
		{
			if (min > queue.front().GetMin())
			{
				min = queue.front().GetMin();
			}
			queue.pop();
		}
		return min;
	}

	template<typename T>
	inline double QueueStack<T>::GetAverage()
	{
		double ave = static_cast <double>(mSum) / mCount;
		return round(ave * 1000) / 1000;
	}

	template<typename T>
	inline T QueueStack<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	inline unsigned int QueueStack<T>::GetCount()
	{
		return mCount;
	}

	template<typename T>
	inline unsigned int QueueStack<T>::GetStackCount()
	{
		return mQueue.size();
	}
}