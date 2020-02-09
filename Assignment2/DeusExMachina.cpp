#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mDeusExMachina = nullptr;

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mDeusExMachina == nullptr)
		{
			mDeusExMachina = new DeusExMachina();
		}
		return mDeusExMachina;
	}

	DeusExMachina::DeusExMachina()
		: mVehicleCount(0)
		, mVehicles()
	{
	}

	DeusExMachina::~DeusExMachina()
	{
		for (size_t i = 0; i < mVehicleCount; i++)
		{
			delete mVehicles[i];
		}
	}

	void DeusExMachina::Travel() const
	{
		for (size_t i = 0; i < mVehicleCount; i++)
		{
			mVehicles[i]->Travel();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mVehicleCount >= 10 || vehicle == nullptr)
		{
			return false;
		}
		mVehicles[mVehicleCount] = vehicle;
		++mVehicleCount;
		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mVehicleCount)
		{
			return false;
		}
		delete mVehicles[i];
		for (; i < mVehicleCount; i++)
		{
			mVehicles[i] = mVehicles[i + 1];
		}
		--mVehicleCount;
		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mVehicleCount == 0)
		{
			return NULL;
		}
		Vehicle* mMaxVehicle = mVehicles[0];
		for (size_t i = 0; i < mVehicleCount; i++)
		{
			if (mMaxVehicle->GetDistance() < mVehicles[i]->GetDistance())
			{
				mMaxVehicle = mVehicles[i];
			}
		}
		return mMaxVehicle;
	}
}