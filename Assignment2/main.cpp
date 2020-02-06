#include <iostream>
#include "Person.h"
#include "Vehicle.h"
using namespace assignment2;
using namespace std;

int main()
{
	Person* p = new Person("Bob", 85);
	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 50);

	Vehicle* a = new Vehicle(2);
	a->AddPassenger(p); // true
	a->AddPassenger(p2); // true
	a->AddPassenger(p3); // false
	return 0;
}