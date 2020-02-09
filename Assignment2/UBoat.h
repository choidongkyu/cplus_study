#pragma once
#include "Vehicle.h"
#include "ISailable.h"
#include "IDivable.h"

namespace assignment2
{
	class UBoat : public Vehicle, public ISailable, public IDivable
	{
	public:
		UBoat();
		~UBoat();

		// Vehicle��(��) ���� ��ӵ�
		virtual unsigned int GetMaxSpeed() const override;

		// ISailable��(��) ���� ��ӵ�
		virtual unsigned int GetSailSpeed() const override;

		// IDivable��(��) ���� ��ӵ�
		virtual unsigned int GetDiveSpeed() const override;

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