#pragma once
#include "Vehicle.h"
#include "IDrivable.h"
#include "Trailer.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();


		// Vehicle을(를) 통해 상속됨
		virtual unsigned int GetMaxSpeed() const override;


		// IDrivable을(를) 통해 상속됨
		virtual unsigned int GetDriveSpeed() const override;

		// Vehicle을(를) 통해 상속됨
		virtual unsigned int GetDistance() const override;
		// Vehicle을(를) 통해 상속됨
		virtual void Travel() override;

	private:
		bool mbIsconnected;
		const Trailer* mTrailer;
		unsigned int mMove;
		unsigned int mRest;
		unsigned int mDistance;
	};
}