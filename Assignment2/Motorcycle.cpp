#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
		, mMove(5)
		, mRest(1)
		, mDistance(0)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}
	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
	unsigned int Motorcycle::GetDriveSpeed() const
	{
		double x = static_cast<double>(Vehicle::GetPassengerWeight());
		double result = (pow(-(x / 15), 3) + 2 * x + 400.0);
		if (result < 0)
		{
			return 0;
		}
		return static_cast<unsigned int>(result + 0.5);
	}
	void Motorcycle::Travel()
	{
		if (mMove == 0 && mRest == 0)
		{
			mMove = 5;
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
	unsigned int Motorcycle::GetDistance() const
	{
		return mDistance;
	}
}