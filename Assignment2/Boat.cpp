#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
		, mMove(2)
		, mRest(1)
		, mDistance(0)
	{
	}

	Boat::~Boat()
	{
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		//Boatplane* bp = new Boatplane(this->GetMaxPassengersCount() + plane.GetMaxPassengersCount());
		const Person* person[MAX_PERSON_COUNT];
		size_t i = 0;
		for (i; i < plane.GetPassengersCount(); i++)
		{
			person[i] = plane.GetPassenger(i);
		}

		for (size_t j = 0; j < this->GetPassengersCount(); j++)
		{
			person[i] = this->GetPassenger(j);
			i++;
		}
		this->GetOff();
		plane.GetOff();
		return Boatplane(person, i, this->GetMaxPassengersCount() + plane.GetMaxPassengersCount());
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	unsigned int Boat::GetSailSpeed() const
	{
		int result = 800 - (10 * Vehicle::GetPassengerWeight());
		if (result < 20)
		{
			return 20;
		}
		return result;
	}
	void Boat::Travel()
	{
		if (mMove == 0 && mRest == 0)
		{
			mMove = 2;
			mRest = 1;
		}
		if (mMove > 0)
		{
			mDistance += GetMaxSpeed();
			--mMove;
		}
		else if (mRest > 0)
		{
			--mRest;
		}
	}
	unsigned int Boat::GetDistance() const
	{
		return mDistance;
	}
}