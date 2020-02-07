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

	cout << a.GetMaxSpeed() << endl;; // ���� �ӵ��� ���� ���� �ӵ����� ������ ������ 648�� ��ȯ(���� 2.4 ����)
	return 0;
}