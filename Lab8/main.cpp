#include <cassert>

#include "FixedVector.h"
#include "FixedBoolVector.h"

using namespace lab8;
int main()
{
	FixedVector<int, 32> v1;
	/*for (size_t i = 0; i < 31; ++i)
	{
		v1.Add(false);
	}*/
	v1.Add(3);

	std::cout<<v1.Get(0)<<std::endl; // 1 ¹ÝÈ¯
	return 0;
}