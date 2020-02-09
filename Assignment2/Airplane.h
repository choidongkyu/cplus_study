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

		// Vehicle��(��) ���� ��ӵ�
		virtual void Travel() override;

	private:
		unsigned int mMove;
		unsigned int mRest;
		unsigned int mDistance;

		// Vehicle��(��) ���� ��ӵ�
		virtual unsigned int GetDistance() const override;
	};
}