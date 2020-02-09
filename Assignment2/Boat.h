#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "ISailable.h"
#include "Airplane.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();

		Boatplane operator+(Airplane& plane);

		// Vehicle��(��) ���� ��ӵ�
		virtual unsigned int GetMaxSpeed() const;

		// ISailable��(��) ���� ��ӵ�
		virtual unsigned int GetSailSpeed() const;

		// Vehicle��(��) ���� ��ӵ�
		virtual void Travel() override;
		// Vehicle��(��) ���� ��ӵ�
		virtual unsigned int GetDistance() const override;
	private:
		unsigned int mMove;
		unsigned int mRest;
		unsigned int mDistance;		
	};
}