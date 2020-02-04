#include "EquilateralTriangleLawn.h"
namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int width)
		: mWidth(width)
	{
	}
	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{
	}
	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		double area = (sqrt(3) / 4) * pow(mWidth, 2);
		return static_cast<unsigned int>(ceil(area));
	}
	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		unsigned round = mWidth * 3;
		return round * 4;
	}
	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned round = mWidth * 3;
		unsigned int price = round * GetTreePrice(fenceType);
		return price;
	}
}