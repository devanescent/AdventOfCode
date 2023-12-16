#pragma once
#include "Point.h"

namespace AdventOfCode::Year2023::Day16
{
	class Beam
	{
	public:
		Point<int> Position;

		// Direction:
		int dx;
		int dy;

		Point<int> GetNext() const
		{
			return Position.MoveBy(dx, dy);
		}

		bool operator<(const Beam& other) const
		{
			if (Position != other.Position)
				return Position < other.Position;
			else if (dx != other.dx)
				return dx < other.dx;
			else
				return dy < other.dy;
		}
	};
}
