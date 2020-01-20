#include "TimeSheet.h"
#include <cmath>

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mMaxEntries(maxEntries)
		, mIndex(0)
		, mName(name)
	{
		mTimeEntries = new int[mMaxEntries];
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mTimeEntries;
	}

	TimeSheet::TimeSheet(const TimeSheet& rhs)
		: mMaxEntries(rhs.mMaxEntries)
		, mIndex(rhs.mIndex)
		, mName(rhs.mName)
	{
		mTimeEntries = new int[rhs.mIndex];
		memcpy(mTimeEntries, rhs.mTimeEntries, mIndex * sizeof(int));
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& rhs)
	{
		mMaxEntries = rhs.mMaxEntries;
		mIndex = rhs.mIndex;
		mName = rhs.mName;
		delete[] mTimeEntries;
		mTimeEntries = new int[rhs.mIndex];
		memcpy(mTimeEntries, rhs.mTimeEntries, mIndex * sizeof(int));
		return *this;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (mIndex < mMaxEntries && timeInHours > 0 && timeInHours < 11)
		{
			*(mTimeEntries + mIndex) = timeInHours;
			++mIndex;
		}
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index > mIndex)
		{
			return -1;
		}
		return *(mTimeEntries + index);
	}

	int TimeSheet::GetTotalTime() const
	{
		int sum = 0;
		for (unsigned int i = 0; i < mIndex; i++)
		{
			sum += *(mTimeEntries + i);
		}
		return sum;
	}

	float TimeSheet::GetAverageTime() const
	{
		float sum = GetTotalTime();
		float ave = sum / mIndex;
		return ave;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float ave = GetAverageTime();
		float sum = 0.0f;
		for (unsigned int i = 0; i < mIndex; i++)
		{
			sum += (*(mTimeEntries + i) - ave) * (*(mTimeEntries + i) - ave);
		}
		return sqrt(sum / mIndex);
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}

	void TimeSheet::SetName(const char* name)
	{
		mName = name;
	}
}