#pragma once
class Point
{
public:
	int x, y;

	Point(int X = 0, int Y = 0) :x(X), y(Y)
	{
	}
	bool operator==(const Point& P)
	{
		return (x == P.x && y == P.y);
	}
};

