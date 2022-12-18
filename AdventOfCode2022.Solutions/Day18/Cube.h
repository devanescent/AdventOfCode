#pragma once

namespace AdventOfCode::Year2022::Day18
{
	struct Cube
	{
		int X;
		int Y;
		int Z;

		bool operator<(const Cube& other) const
		{
			if (X != other.X)
				return X < other.X;
			else if (Y != other.Y)
				return Y < other.Y;
			else
				return Z < other.Z;
		}

		bool operator==(const Cube& other) const
		{
			return X == other.X && Y == other.Y && Z == other.Z;
		}
	};
}
