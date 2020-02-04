#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
		:mSodRollArea(0.3)
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		double price = GetArea() * GetLawnPrice(grassType) / 100.0;
		return static_cast<unsigned int>(round(price));
	}

	unsigned int Lawn::GetLawnPrice(eGrassType grassType) const
	{
		switch (grassType)
		{
		case BERMUDA:
			return 800;

		case BAHIA:
			return 500;

		case BENTGRASS:
			return 300;

		case PERENNIAL_RYEGRASS:
			return 250;

		case ST_AUGUSTINE:
			return 450;

		default:
			return 0;
		}
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		double sodRollsCount = GetArea() / mSodRollArea;
		return static_cast<unsigned int>(ceil(sodRollsCount));
	}
	unsigned int Lawn::GetTreePrice(eFenceType grassType) const
	{
		switch (grassType)
		{
		case RED_CEDAR:
			return 6;

		case SPRUCE:
			return 7;

		default:
			return 0;
		}
	}
}
