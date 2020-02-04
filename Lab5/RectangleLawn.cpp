#include "RectangleLawn.h"


namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
		: mWidth(width)
		, mHeight(height)
	{
	}

	RectangleLawn::~RectangleLawn()
	{
	}
	unsigned int RectangleLawn::GetArea() const
	{
		return mWidth * mHeight;
	}
	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		unsigned int round = (mWidth + mHeight) * 2;
		return round * 4;
	}
	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int round = (mWidth + mHeight) * 2;
		unsigned price = round * GetTreePrice(fenceType);
		return price;
	}
}
