#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned int width)
		: RectangleLawn(width, width)
	{
	}
	SquareLawn::~SquareLawn()
	{
	}
	unsigned int SquareLawn::GetArea() const
	{
		return RectangleLawn::GetArea();
	}
}
