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
		Boatplane* bp = new Boatplane(this->GetMaxPassengersCount() + plane.GetMaxPassengersCount());
		for (size_t i = 0; i < plane.GetPassengersCount(); i++)
		{
			bp->AddPassenger(plane.GetPassenger(i));
		}

		for (size_t i = 0; i < this->GetPassengersCount(); i++)
		{
			bp->AddPassenger(this->GetPassenger(i));
		}
		this->GetOff();
		plane.GetOff();
		return Boatplane(*bp);
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