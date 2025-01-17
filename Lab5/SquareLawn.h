#pragma once
#include "RectangleLawn.h"

namespace lab5
{
	class SquareLawn : public RectangleLawn
	{
	public:
		SquareLawn(unsigned int width);
		virtual ~SquareLawn();

		virtual unsigned int GetArea() const;
	};
}
