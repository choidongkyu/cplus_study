#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mPersonCount(0)
		, mPersons()
		, mMaxPassengersCount(maxPassengersCount)
	{
	}

	Vehicle::~Vehicle()
	{
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mPersonCount >= mMaxPassengersCount)
		{
			return false;
		}
		mPersons[mPersonCount] = person;
		++mPersonCount;
		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i >= mPersonCount)
		{
			return false;
		}
		for (; i < mPersonCount; i++)
		{
			mPersons[i] = mPersons[i + 1];
		}
		--mPersonCount;
		return false;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return 0;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return 0;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		return NULL;
	}
}