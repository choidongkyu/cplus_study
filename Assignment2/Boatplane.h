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

		// Vehicle을(를) 통해 상속됨
		virtual unsigned int GetMaxSpeed() const override;

		// ISailable을(를) 통해 상속됨
		virtual unsigned int GetSailSpeed() const override;

		// IFlyable을(를) 통해 상속됨
		virtual unsigned int GetFlySpeed() const override;

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