#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}
	unsigned int Boatplane::GetMaxSpeed() const
	{
		return 0;
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
}