#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
		, mbIsconnected(false)
		, mTrailer(NULL)
		, mMove(5)
		, mRest(1)
		, mDistance(0)
	{
	}

	Sedan::~Sedan()
	{
		RemoveTrailer();
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mbIsconnected)
		{
			return false;
		}
		mRest = 2;
		mTrailer = trailer;
		mbIsconnected = true;
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (!mbIsconnected)
		{
			return false;
		}
		delete mTrailer;
		mbIsconnected = false;
		return true;
	}
	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int weight = Vehicle::GetPassengerWeight();
		if (mbIsconnected)
		{
			weight += mTrailer->GetWeight();
		}
		if (weight <= 80)
		{
			return 480;
		}
		if (weight > 350)
		{
			return 300;
		}
		if (weight > 260)
		{
			return 380;
		}
		if (weight > 160)
		{
			return 400;
		}
		if (weight > 80)
		{
			return 458;
		}
		return 0;
	}
	void Sedan::Travel()
	{
		if (mMove == 0 && mRest == 0)
		{
			mMove = 5;
			if (mbIsconnected)
			{
				mRest = 2;
			}
			else
			{
				mRest = 1;
			}
		}
		if (mMove > 0)
		{
			mDistance += GetMaxSpeed();
			--mMove;
		}
		else if (mRest > 0)
		{
			--mRest;
		}
	}
	unsigned int Sedan::GetDistance() const
	{
		return mDistance;
	}
}