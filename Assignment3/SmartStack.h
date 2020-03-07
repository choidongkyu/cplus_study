#pragma once
#include <stack>
#include <limits.h>
#include <cmath>
namespace assignment3
{
	template <typename T>
	class SmartStack
	{
	public:
		SmartStack();
		~SmartStack() = default;
		void Push(T data);
		T Pop();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();

	private:
		std::stack<T> mStack;
		std::stack<T> mMaxStack;
		std::stack<T> mMinStack;
		T mSum;
		double mSquaredSum;
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
		: mSum(0)
		, mSquaredSum(0)
	{
	}

	template<typename T>
	inline void SmartStack<T>::Push(T data)
	{
		if (mStack.empty())
		{
			mMaxStack.push(data);
			mMinStack.push(data);
		}
		else
		{
			if (data > mMaxStack.top())
			{
				mMaxStack.push(data);
			}
			else {
				mMaxStack.push(mMaxStack.top());
			}

			if (data < mMinStack.top())
			{
				mMinStack.push(data);
			}
			else
			{
				mMinStack.push(mMinStack.top());
			}
		}
		mStack.push(data);
		mSum += data;
		mSquaredSum += static_cast<double>(data)* data;

	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		T value = mStack.top();
		mSum -= mStack.top();
		mSquaredSum -= static_cast<double>(mStack.top())* mStack.top();
		mStack.pop();
		mMaxStack.pop();
		mMinStack.pop();

		return value;
	}

	template<typename T>
	inline T SmartStack<T>::Peek()
	{
		return mStack.top();
	}

	template<typename T>
	inline T SmartStack<T>::GetMax()
	{
		if (mStack.empty())
		{
			return std::numeric_limits<T>::lowest();
		}
		return mMaxStack.top();
	}

	template<typename T>
	inline T SmartStack<T>::GetMin()
	{
		if (mStack.empty())
		{
			return std::numeric_limits<T>::max();
		}
		return mMinStack.top();
	}

	template<typename T>
	inline double SmartStack<T>::GetAverage()
	{
		double ave = static_cast <double>(mSum) / mStack.size();

		return round(ave * 1000) / 1000;
	}

	template<typename T>
	inline T SmartStack<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance()
	{
		double ave = static_cast <double>(mSum) / mStack.size();//22.667 msquaredsum = 1910
		double deviation = (static_cast<double>(mSquaredSum) / mStack.size()) - (ave * ave);
		return round(deviation * 1000) / 1000;
	}

	template<typename T>
	inline double SmartStack<T>::GetStandardDeviation()
	{
		double result = sqrt(GetVariance());
		return round(result * 1000) / 1000;
	}


	template<typename T>
	inline unsigned int SmartStack<T>::GetCount()
	{
		return mStack.size();
	}
}