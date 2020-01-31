#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mSize(0)
	{
		mPoints = new Point * [10];
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mSize(other.mSize)
	{
		mPoints = new Point * [10];
		memcpy(mPoints, other.mPoints, sizeof(mPoints));
	}

	PolyLine::~PolyLine()
	{
		delete[] mPoints;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mSize >= 10)
		{
			return false;
		}
		*(mPoints + mSize) = new Point(x, y);
		++mSize;
		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mSize >= 10)
		{
			return false;
		}
		if (point != nullptr)
		{
			memcpy(mPoints + mSize, &point, sizeof(point));
			++mSize;
		}
		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mSize)
		{
			return false;
		}
		delete* (mPoints + i);
		for (; i < mSize; i++)
		{
			*(mPoints + i) = *(mPoints + i + 1);
		}
		--mSize;
		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		float maxX = mPoints[0]->GetX();
		float minX = mPoints[0]->GetX();
		float maxY = mPoints[0]->GetY();
		float minY = mPoints[0]->GetY();
		for (size_t i = 0; i < mSize; i++)
		{
			if (maxX < mPoints[i]->GetX())
			{
				maxX = mPoints[i]->GetX();
			}

			if (minX > mPoints[i]->GetX())
			{
				minX = mPoints[i]->GetX();
			}

			if (maxY < mPoints[i]->GetY())
			{
				maxY = mPoints[i]->GetY();
			}

			if (minY > mPoints[i]->GetY())
			{
				minY = mPoints[i]->GetY();
			}
		}
		float area = (maxX - minX) * (maxY - minY);
		if (area < 0)
		{
			return false;
		}
		outMin->SetXY(minX, minY);
		outMax->SetXY(maxX, maxY);
		return true;
	}

	void PolyLine::Printf() const
	{
		for (size_t i = 0; i < mSize; i++)
		{
			mPoints[i]->Printf();
		}
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= mSize)
		{
			return NULL;
		}
		return *(mPoints + i);
	}
}