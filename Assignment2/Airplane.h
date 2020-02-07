#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "IDrivable.h"
#include "IFlyable.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IDrivable, public IFlyable
	{
	public:
		virtual unsigned int GetDriveSpeed() const;
		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetMaxSpeed() const;
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		Boatplane operator+(Boat& boat);
	};
}