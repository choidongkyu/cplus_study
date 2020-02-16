#include "Airplane.h"

namespace assignment2
{
	unsigned int Airplane::GetDriveSpeed() const
	{
		double weight = static_cast<double>(Vehicle::GetPassengerWeight());
		double result = 4.0 * pow(M_E, (-weight + 400) / 70);
		return static_cast<unsigned int>(result + 0.5);
	}
	unsigned int Airplane::GetFlySpeed() const
	{
		double weight = static_cast<double>(Vehicle::GetPassengerWeight());
		double result = 200.0 * pow(M_E, (-weight + 800) / 500);
		return static_cast<unsigned int>(result + 0.5);
	}
	unsigned int Airplane::GetMaxSpeed() const
	{
		return std::max(GetFlySpeed(), GetDriveSpeed());
	}
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
		, mMove(1)
		, mRest(3)
		, mDistance(0)
	{
	}

	Airplane::~Airplane()
	{
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane* bp = new Boatplane(this->GetMaxPassengersCount() + boat.GetMaxPassengersCount());
		for (size_t i = 0; i < this->GetPassengersCount(); i++)
		{
			bp->AddPassenger(this->GetPassenger(i));
		}

		for (size_t i = 0; i < boat.GetPassengersCount(); i++)
		{
			bp->AddPassenger(boat.GetPassenger(i));
		}
		this->GetOff();
		boat.GetOff();
		return Boatplane(*bp);
	}
	void Airplane::Travel()
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
	unsigned int Airplane::GetDistance() const
	{
		return mDistance;
	}
}