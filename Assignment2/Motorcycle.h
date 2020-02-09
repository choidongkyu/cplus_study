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

		// Vehicle을(를) 통해 상속됨
		virtual unsigned int GetMaxSpeed() const override;
		// IDrivable을(를) 통해 상속됨
		virtual unsigned int GetDriveSpeed() const override;
		// Vehicle을(를) 통해 상속됨
		virtual void Travel() override;
		// Vehicle을(를) 통해 상속됨
		virtual unsigned int GetDistance() const override;
	private:
		unsigned int mMove;
		unsigned int mRest;
		unsigned int mDistance;
	};
}