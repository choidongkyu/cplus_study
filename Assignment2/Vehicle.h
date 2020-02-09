#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>
#include "Person.h"
#define MAX_PERSON_COUNT 100
namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		~Vehicle();
		virtual unsigned int GetMaxSpeed() const = 0;
		virtual void Travel() = 0;
		virtual unsigned int GetDistance() const = 0;
		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetPassengerWeight() const;
		const void GetOff();

	private:
		const Person* mPersons[MAX_PERSON_COUNT];
		size_t mPersonCount;
		size_t mMaxPassengersCount;
	};
}