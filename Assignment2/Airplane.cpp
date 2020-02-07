#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

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
		return GetFlySpeed();
	}
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(0);
		return bp;
	}
}