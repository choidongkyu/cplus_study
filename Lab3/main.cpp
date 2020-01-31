#include <iostream>
#include "TimeSheet.h"

using namespace std;
using namespace lab3;
int main()
{
	TimeSheet p("Pope", 10);

	p.AddTime(3);
	p.AddTime(16);
	p.AddTime(6);
	p.AddTime(5);
	p.AddTime(1);
	p.AddTime(2);
	p.AddTime(2);
	p.AddTime(2);
	p.AddTime(11);
	p.AddTime(2);
	p.AddTime(2);
	p.AddTime(2);
	p.AddTime(2);

	TimeSheet p2("eoeo", 10);
	p2.AddTime(4);
	p2 = p;
	//cout<<p.GetAverageTime()<<endl; // 4.1667 ¹ÝÈ¯

	for (int i = 0; i < 30; i++)
	{
		cout << "p2.get(" << i << ") = " << p2.GetTimeEntry(i) << endl;
	}

	return 0;
}