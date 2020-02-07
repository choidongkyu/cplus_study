#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "ISailable.h"

namespace assignment2
{
	class Airplane;

	class Boat :public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();

		Boatplane operator+(Airplane& plane);

		// Vehicle��(��) ���� ��ӵ�
		virtual unsigned int GetMaxSpeed() const;

		// ISailable��(��) ���� ��ӵ�
		virtual unsigned int GetSailSpeed() const;
	};
}