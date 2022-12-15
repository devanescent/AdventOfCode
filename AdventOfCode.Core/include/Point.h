#pragma once
#include <cmath>

namespace AdventOfCode
{
	struct Point
	{
		int X;
		int Y;

		Point() : X(0), Y(0) {}
		Point(int x, int y) : X(x), Y(y) {}

		Point WithX(int x) const { return Point{ x, Y }; }
		Point WithY(int y) const { return Point{ X, y }; }

		Point MoveXBy(int dx) const { return Point{ X + dx, Y }; }
		Point MoveYBy(int dy) const { return Point{ X, Y + dy }; }
		Point MoveBy(int dx, int dy) const { return Point{ X + dx, Y + dy }; }

		int DistanceTo(const Point& other) const
		{
			return std::abs(X - other.X) + std::abs(Y - other.Y);
		}

		// Make points sortable, e.g. for using in a map
		bool operator<(const Point& other) const
		{
			if (X != other.X)
				return X < other.X;
			else
				return Y < other.Y;
		}

		bool operator==(const Point& other) const
		{
			return X == other.X && Y == other.Y;
		}
	};
}