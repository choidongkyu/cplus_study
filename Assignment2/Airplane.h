#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "IDrivable.h"
#include "IFlyable.h"
#include "Boat.h"

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

		// Vehicle을(를) 통해 상속됨
		virtual void Travel() override;

	private:
		unsigned int mMove;
		unsigned int mRest;
		unsigned int mDistance;

		// Vehicle을(를) 통해 상속됨
		virtual unsigned int GetDistance() const override;
	};
}