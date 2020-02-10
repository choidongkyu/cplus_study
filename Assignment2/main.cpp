#include <cassert>
#include <crtdbg.h>
#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"

using namespace assignment2;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(186);
	//_CrtSetBreakAlloc(190);
	//_CrtSetBreakAlloc(164);
	//_CrtSetBreakAlloc(163);
	//_CrtSetBreakAlloc(162);
	//_CrtSetBreakAlloc(161);
	//_CrtSetBreakAlloc(159);
	//_CrtSetBreakAlloc(158);
	//_CrtSetBreakAlloc(157);
	//_CrtSetBreakAlloc(156);
	//_CrtSetBreakAlloc(155);
	//_CrtSetBreakAlloc(154);
	//_CrtSetBreakAlloc(152);
	//_CrtSetBreakAlloc(151);
	//_CrtSetBreakAlloc(150);

	DeusExMachina* deusExMachina1 = DeusExMachina::GetInstance();
	Sedan* sedan2 = new Sedan();
	sedan2->AddTrailer(new Trailer(60));
	deusExMachina1->AddVehicle(sedan2);
	delete deusExMachina1;
	return 0;
}