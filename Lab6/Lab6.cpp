#include "Lab6.h"
using namespace std;
namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		
		return 0;
	}

	int Min(const std::vector<int>& v)
	{
		return 0;
	}

	int Max(const std::vector<int>& v)
	{
		return 0;
	}

	float Average(const std::vector<int>& v)
	{
		return 0.0f;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}
		vector<int>::const_iterator iter = v.begin();
		int max = -INT16_MAX;
		size_t maxCount = 0;
		while (iter != v.end())
		{
			size_t count = 0;
			for (int i = 0; i < v.size(); i++)
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

	}

}