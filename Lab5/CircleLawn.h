#pragma once
#include "Lawn.h"
#define PI 3.14

namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn(unsigned int radius);
		virtual ~CircleLawn();

		virtual unsigned int GetArea() const;
	private:
		unsigned int mRadius;
	};
}