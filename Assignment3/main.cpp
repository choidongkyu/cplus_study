#include <iostream>
#include "SmartStack.h"

using namespace assignment3;
using namespace std;
int main()
{
	SmartStack<int> s;
	s.Push(6);
	s.Push(5);
	s.Push(-2); // [ 6, 5, -2 ]

	double standardDeviation = s.GetStandardDeviation(); // 3.559

	//int popped = s.Peek(); // popped�� ���� -2. s�� ���: [ 6, 5 ]
	cout << standardDeviation << endl;
	return 0;
}