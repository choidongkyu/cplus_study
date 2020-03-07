#pragma once
#include <queue>
#include <limits.h>
#include <cmath>

namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		~SmartQueue() = default;
		void Enqueue(T data);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();

	private:
		std::queue<T> mQueue;
		T mSum;
		double mSquaredSum;
	};

	template<typename T>
	inline SmartQueue<T>::SmartQueue()
		: mSum(0)
		, mSquaredSum(0)
	{
	}

	template<typename T>
	inline void SmartQueue<T>::Enqueue(T data)
	{
		mQueue.push(data);
		mSum += data;
		mSquaredSum += static_cast<double>(data)* data;
	}

	template<typename T>
	inline T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}

	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		T data = mQueue.front();
		mSum -= data;
		mSquaredSum -= static_cast<double>(data)* data;
		mQueue.pop();
		return data;
	}

	template<typename T>
	inline T SmartQueue<T>::GetMax()
	{
		T max = std::numeric_limits<T>::lowest();
		std::queue<T> queue(mQueue);
		while (!queue.empty())
		{
			if (max < queue.front())
			{
				max = queue.front();
			}
			queue.pop();
		}
		return max;
	}

	template<typename T>
	inline T SmartQueue<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();
		std::queue<T> queue(mQueue);
		while (!queue.empty())
		{
			if (min > queue.front())
			{
				min = queue.front();
			}
			queue.pop();
		}
		return min;
	}

	template<typename T>
	inline double SmartQueue<T>::GetAverage()
	{
		double ave = static_cast <double>(mSum) / mQueue.size();
		return round(ave * 1000) / 1000;
	}

	template<typename T>
	inline T SmartQueue<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	inline double SmartQueue<T>::GetVariance()
	{
		double ave = static_cast <double>(mSum) / mQueue.size();
		double deviation = (static_cast<double>(mSquaredSum) / mQueue.size()) - (ave * ave);
		return round(deviation * 1000) / 1000;
	}

	template<typename T>
	inline double SmartQueue<T>::GetStandardDeviation()
	{
		double result = sqrt(GetVariance());
		return round(result * 1000) / 1000;
	}

	template<typename T>
	inline unsigned int SmartQueue<T>::GetCount()
	{
		return mQueue.size();
	}
}