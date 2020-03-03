#include <cassert>
#include <iostream>
#include "Lab6.h"

int main()
{
	std::vector<int> v;

	int max = lab6::Max(v);
	std::cout << max << std::endl;

	return 0;
}