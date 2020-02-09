#pragma once
#include "Vehicle.h"
#include "IDrivable.h"
namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		~Motorcycle();

		// Vehicle��(��) ���� ��ӵ�
		virtual unsigned int GetMaxSpeed() const override;
		// IDrivable��(��) ���� ��ӵ�
		virtual unsigned int GetDriveSpeed() const override;
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