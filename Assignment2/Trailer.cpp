#include "Trailer.h"

namespace assignment2
{
	Trailer::Trailer(const Trailer* other)
		: mWeight(other->mWeight)
	{
	}
	Trailer::Trailer(unsigned int weight)
		: mWeight(weight)
	{
	}

	Trailer::~Trailer()
	{
	}

	unsigned int Trailer::GetWeight() const
	{
		return mWeight;
	}
}