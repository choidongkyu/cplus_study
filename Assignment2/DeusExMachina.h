#pragma once
#include "Vehicle.h"
using namespace std;
namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		~DeusExMachina();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;
	private:
		DeusExMachina();
		static DeusExMachina* mDeusExMachina;
		Vehicle* mVehicles[10];
		size_t mVehicleCount;
	};
}