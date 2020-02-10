#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
		, mMove(2)
		, mRest(4)
		, mDistance(0)
	{
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		unsigned int result = std::max(GetDiveSpeed(), GetSailSpeed());
		return result;
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		double x = static_cast<double>(Vehicle::GetPassengerWeight());
		double result = 550 - x / 10;
		if (result < 200)
		{
			return 200;
		}
		return static_cast<unsigned int>(result + 0.5);
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		double x = static_cast<double>(Vehicle::GetPassengerWeight());
		double result = 500 * log((x + 150) / 150) + 30;
		return static_cast<unsigned int>(result + 0.5);
	}

	void UBoat::Travel()
	{
		if (mMove == 0 && mRest == 0)
		{
			mMove = 2;
			mRest = 4;
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
	unsigned int UBoat::GetDistance() const
	{
		return mDistance;
	}
}