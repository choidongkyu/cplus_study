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
		for (size_t i = 0; i < mPersonCount; i++)
		{
			delete mPersons[i];
		}
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
		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPersonCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	unsigned int Vehicle::GetPassengerWeight() const
	{
		unsigned int result = 0;
		for (size_t i = 0; i < mPersonCount; i++)
		{
			result += mPersons[i]->GetWeight();
		}
		return result;
	}

	const void Vehicle::Printfs() const
	{
		for (size_t i = 0; i < mPersonCount; i++)
		{
			mPersons[i]->Printf();
		}
	}

	const void Vehicle::GetOff()
	{
		for (size_t i = 0; i < mPersonCount; i++)
		{
			mPersons[i] = nullptr;
		}
		mPersonCount = 0;
		return ;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i >= mPersonCount)
		{
			return NULL;
		}
		return mPersons[i];
	}
}