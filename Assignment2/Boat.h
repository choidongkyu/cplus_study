#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "ISailable.h"
#include "Airplane.h"

namespace assignment2
{
	class Airplane;

	class Boat :public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();

		Boatplane operator+(Airplane& plane);

		// Vehicle을(를) 통해 상속됨
		virtual unsigned int GetMaxSpeed() const;

		// ISailable을(를) 통해 상속됨
		virtual unsigned int GetSailSpeed() const;
	};
}