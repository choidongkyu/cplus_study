#include "FixedVector.h"
#include <iostream>
using namespace std;
using namespace lab8;
int main()
{
	FixedVector<int, 4> v1;
	v1.Add(1); // [ 1 ]
	v1.Add(2); // [ 1, 2 ]
	v1.Add(3); // [ 1, 2, 3 ]
	v1.Add(4); // [ 1, 2, 3, 4 ]

	v1.Remove(3); // [ 1, 2, 4 ]
	v1.Remove(3); // false ¹ÝÈ¯

	return 0;
}