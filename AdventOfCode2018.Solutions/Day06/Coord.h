#pragma once

namespace AdventOfCode::Year2018::Day06
{
	class Coord
	{
	public:
		int X, Y;
		Coord(int x, int y) : X(x), Y(y) {}

		bool operator<(const Coord& other) const
		{
			if (X != other.X)
				return X < other.X;
			else
				return Y < other.Y;
		}

		int GetDistanceTo(const Coord& other) const
		{
			return std::abs(X - other.X) + std::abs(Y - other.Y);
		};
	};

	class BoundingBox
	{
	public:
		int XMin, XMax;
		int YMin, YMax;
	};
}