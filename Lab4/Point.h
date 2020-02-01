#pragma once

namespace lab4
{
	class Point
	{
	public:
		Point();
		Point(float x, float y);
		Point(const Point& other);
		~Point();

		Point operator+(const Point& other) const;
		Point operator-(const Point& other) const;
		float Dot(const Point& other) const;
		Point operator*(float operand) const;
		Point& operator=(const Point& other);
		friend Point operator*(float operand, Point& other);

		float GetX() const;
		float GetY() const;
		void SetXY(const float x, const float y);
	private:
		float mX;
		float mY;
	};
}