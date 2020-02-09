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


		// Vehicle��(��) ���� ��ӵ�
		virtual unsigned int GetMaxSpeed() const override;


		// IDrivable��(��) ���� ��ӵ�
		virtual unsigned int GetDriveSpeed() const override;

		// Vehicle��(��) ���� ��ӵ�
		virtual unsigned int GetDistance() const override;
		// Vehicle��(��) ���� ��ӵ�
		virtual void Travel() override;

	private:
		bool mbIsconnected;
		const Trailer* mTrailer;
		unsigned int mMove;
		unsigned int mRest;
		unsigned int mDistance;
	};
}