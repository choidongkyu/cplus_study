#include <iostream>
#include "Person.h"
#include "Vehicle.h"
#include "Airplane.h"
using namespace assignment2;
using namespace std;

int main()
{
	Person* p = new Person("Bob", 85);
	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 52);

	Airplane a(5);
	a.AddPassenger(p);
	a.AddPassenger(p2);
	a.AddPassenger(p3);

	cout << a.GetMaxSpeed() << endl;; // 비행 속도가 도로 주행 속도보다 빠르기 때문에 648을 반환(섹션 2.4 참고)
	return 0;
}