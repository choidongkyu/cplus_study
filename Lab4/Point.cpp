#include "Point.h"
#include <iostream>

namespace lab4
{
	Point::Point(float x, float y)
		: mX(x)
		, mY(y)
	{
	}

	Point::Point()
		: mX(0)
		, mY(0)
	{
	}

	Point::~Point()
	{
	}

	Point Point::operator+(const Point& other) const
	{

		return Point(mX + other.mX, mY + other.mY);
	}

	Point Point::operator-(const Point& other) const
	{
		return Point(mX - other.mX, mY - other.mY);
	}

	float Point::Dot(const Point& other) const
	{
		return (mX * other.mX) + (mY * other.mY);
	}

	Point Point::operator*(float operand) const
	{
		return Point(mX * operand, mY * operand);
	}

	void Point::Printf() const
	{
		std::cout << "x=" << mX << ", y=" << mY << std::endl;
	}


	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}
	void Point::SetXY(const float x, const float y)
	{
		mX = x;
		mY = y;
		return;
	}
	Point operator*(float operand, Point& other)
	{
		return Point(operand * other.mX, operand * other.mY);
	}
}