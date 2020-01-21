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
		mTimeEntries = new int[rhs.mMaxEntries];
		memcpy(mTimeEntries, rhs.mTimeEntries, mMaxEntries * sizeof(int));
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& rhs)
	{
		if (memcmp(this, &rhs, mMaxEntries * sizeof(int)) == 0)
		{
			return *this;
		}
		mMaxEntries = rhs.mMaxEntries;
		mIndex = rhs.mIndex;
		mName = rhs.mName;
		if (mTimeEntries != nullptr) {
			delete[] mTimeEntries;
		}
		mTimeEntries = new int[mMaxEntries];
		memcpy(mTimeEntries, rhs.mTimeEntries, mMaxEntries * sizeof(int));

		return *this;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (mIndex > mMaxEntries - 1 || timeInHours <= 0 || timeInHours > 10)
		{
			return;
		}
		*(mTimeEntries + mIndex) = timeInHours;
		++mIndex;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index >= mIndex)
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
		int sum = GetTotalTime();
		if (mIndex == 0)
		{
			return 0.0f;
		}
		float ave = static_cast <float>(sum) / mIndex;
		return ave;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float ave = GetAverageTime();
		float sum = 0.0f;
		if (mIndex == 0)
		{
			return 0.0f;
		}
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