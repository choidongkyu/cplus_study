#include "FixedVector.h"
#include "FixedBoolVector.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace lab8;
int main()
{
	FixedVector<bool, 35> v;
	for (size_t i = 0; i < 35; ++i)
	{
		v.Add(true);
	}
	return 0;
}