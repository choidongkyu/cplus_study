#include "CircleLawn.h"

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int radius)
		: mRadius(radius)
	{
	}
	CircleLawn::~CircleLawn()
	{
	}
	unsigned int CircleLawn::GetArea() const
	{
		double area = (static_cast<double>(mRadius) * static_cast<double>(mRadius))* PI;
		return static_cast<unsigned int>(round(area));
	}
}