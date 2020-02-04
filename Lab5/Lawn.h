#pragma once

#include "eGrassType.h"
#include "eFenceType.h"
#include <cmath>

namespace lab5
{
	class Lawn
	{
	public:
		Lawn();
		virtual ~Lawn();
		Lawn(int width);

		virtual unsigned int GetArea() const = 0;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetLawnPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;
		unsigned int GetTreePrice(eFenceType grassType) const;

	private:
		double mSodRollArea;
	};
}
