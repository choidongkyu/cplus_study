#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
		, mMove(1)
		, mRest(3)
		, mDistance(0)
	{
	}

	Boatplane::~Boatplane()
	{
	}
	unsigned int Boatplane::GetMaxSpeed() const
	{
		return std::max(GetSailSpeed(),GetFlySpeed());
	}
	unsigned int Boatplane::GetSailSpeed() const
	{
		double result = 800 - (1.7 * Vehicle::GetPassengerWeight());
		if (result < 20)
		{
			return 20;
		}
		return static_cast<unsigned int>(result);
	}
	unsigned int Boatplane::GetFlySpeed() const
	{
		double weight = static_cast<double>(Vehicle::GetPassengerWeight());
		double result = 150.0 * pow(M_E, (-weight + 500) / 300);
		return static_cast<unsigned int>(result + 0.5);
	}

	void Boatplane::Travel()
	{
		if (mMove == 0 && mRest == 0)
		{
			mMove = 1;
			mRest = 3;
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
	unsigned int Boatplane::GetDistance() const
	{
		return mDistance;
	}
}