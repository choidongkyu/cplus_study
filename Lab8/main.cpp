#include <cassert>

#include "FixedVector.h"
#include "FixedBoolVector.h"

using namespace lab8;
int main()
{
	FixedVector<int, 5> v1;
	v1.Add(1);
	v1.Add(2);
	v1.Add(3);
	v1.Add(4);

	v1.Get(2)=3; // 4 ¹ÝÈ¯
	return 0;
}