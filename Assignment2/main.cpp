#include <cassert>
#include <iostream>
#include <iomanip>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "UBoat.h"
#include "Trailer.h"
#include "DeusExMachina.h"
#include "Person.h"


#define STR(name) #name

using namespace assignment2;
using namespace std;

int main()
{
	const char* MAX_SPEED_LABLE = "Max Speed: ";
	const char* CUR_P_LABLE = "Current Person: ";
	const unsigned int MAX_CAPACITY = 10;

	Sedan sedanTest;
	Trailer* t1 = new Trailer(10);
	Trailer* t2 = new Trailer(20);
	Trailer* t3 = new Trailer(20);

	assert(sedanTest.AddTrailer(t1));
	assert(!sedanTest.AddTrailer(t1));
	assert(!sedanTest.AddTrailer(t2));
	assert(sedanTest.RemoveTrailer());
	assert(sedanTest.AddTrailer(t2));
	sedanTest.AddPassenger(new Person("wer", 20));
	//assert(sedanTest.RemoveTrailer());

	Sedan copysedan(sedanTest);

	return 0;
}