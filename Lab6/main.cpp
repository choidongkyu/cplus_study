#include <iostream>
#include "Lab6.h"
using namespace std;
using namespace lab6;
int main()
{
	std::vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(4);
	v.push_back(12);
	v.push_back(7);
	v.push_back(11);

	lab6::SortDescending(v); // v¿« ø‰º“: [ 12, 11, 7, 4, 4, 3 ]
	Printf(v);
	return 0;
}