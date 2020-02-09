#pragma once
#include "Vehicle.h"
#include "ISailable.h"
#include "IFlyable.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public ISailable, public IFlyable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();

		// Vehicle��(��) ���� ��ӵ�
		virtual unsigned int GetMaxSpeed() const override;

		// ISailable��(��) ���� ��ӵ�
		virtual unsigned int GetSailSpeed() const override;

		// IFlyable��(��) ���� ��ӵ�
		virtual unsigned int GetFlySpeed() const override;

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