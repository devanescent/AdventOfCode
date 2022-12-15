#pragma once
#include <cmath>

namespace AdventOfCode
{
	template<typename T>
	struct Point
	{
		T X;
		T Y;

		Point() : X(0), Y(0) {}
		Point(T x, T y) : X(x), Y(y) {}

		Point WithX(T x) const { return Point{ x, Y }; }
		Point WithY(T y) const { return Point{ X, y }; }

		Point MoveXBy(T dx) const { return Point{ X + dx, Y }; }
		Point MoveYBy(T dy) const { return Point{ X, Y + dy }; }
		Point MoveBy(int dx, int dy) const { return Point{ X + dx, Y + dy }; }

		T DistanceTo(const Point& other) const
		{
			T dx = X > other.X ? X - other.X : other.X - X;
			T dy = Y > other.Y ? Y - other.Y : other.Y - Y;
			return dx + dy;
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