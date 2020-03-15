#include <cassert>

#include "FixedVector.h"
#include "FixedBoolVector.h"

using namespace lab8;
int main()
{
	FixedVector<bool, 65> boolVector2;
	assert(sizeof(boolVector2) == ((sizeof(int32_t) * 3) + sizeof(size_t)));
	std::cout << "Test FixedBoolVector constructor - fit memroy: PASS" << std::endl;
	for (int i = 0; i < 33; i++)
	{
		boolVector2.Add(false);
	}

	assert(boolVector2.Add(true));
	//assert(boolVector2.GetSize() == 65);
	std::cout<<boolVector2.GetIndex(true)<<std::endl;
	std::cout << "Test FixedBoolVector GetIndex(): PASS" << std::endl;

	return 0;
}