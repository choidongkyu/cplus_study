#include "Lab6.h"

using namespace std;
namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int sum = 0;
		vector<int>::const_iterator iter = v.begin();
		for (size_t i = 0; i < v.size(); i++)
		{
			sum += *iter;
			++iter;
		}
		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		int min = INT32_MAX;
		if (v.size() == 0)
		{
			return min;
		}
		vector<int>::const_iterator iter = v.begin();
		for (size_t i = 0; i < v.size(); i++)
		{
			if (min > * iter)
			{
				min = *iter;
			}
			++iter;
		}
		return min;
	}

	int Max(const std::vector<int>& v)
	{
		int max = INT32_MIN;
		vector<int>::const_iterator iter = v.begin();
		if (v.size() == 0)
		{
			return max;
		}
		for (size_t i = 0; i < v.size(); i++)
		{
			if (max < *iter)
			{
				max = *iter;
			}
			++iter;
		}
		return max;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}
		return static_cast<float>(Sum(v)) / v.size();
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}
		vector<int>::const_iterator iter = v.begin();
		int max = INT32_MIN;
		size_t maxCount = 0;
		while (iter != v.end())
		{
			size_t count = 0;
			for (size_t i = 0; i < v.size(); i++)
			{
				if (*iter == v[i])
				{
					++count;
				}
			}
			if (count > maxCount)
			{
				maxCount = count;
				max = *iter;
			}
			++iter;
		}
		return max;
	}

	void SortDescending(std::vector<int>& v)
	{
		vector<int>::const_iterator iter = v.begin();
		int tmp = 0;
		for (size_t i = 0; i < v.size(); i++)
		{
			for (size_t j = 0; j < v.size() - i - 1; j++)
			{
				if (v[j] < v[j + 1])
				{
					tmp = v[j];
					v[j] = v[j + 1];
					v[j + 1] = tmp;
				}
			}
		}
	}

	/*void Printf(std::vector<int>& v)
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout << v[i] << std::endl;
		}
	}*/

}