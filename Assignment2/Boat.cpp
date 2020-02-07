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
		Boatplane bp(5);
		return bp;
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