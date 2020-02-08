#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane* bp = new Boatplane(this->GetMaxPassengersCount() + plane.GetMaxPassengersCount());
		for (size_t i = 0; i < this->GetPassengersCount(); i++)
		{
			bp->AddPassenger(new Person(this->GetPassenger(i)));
		}

		for (size_t i = 0; i < plane.GetPassengersCount(); i++)
		{
			bp->AddPassenger(new Person(plane.GetPassenger(i)));
		}
		this->GetOff();
		plane.GetOff();
		return *bp;
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
}