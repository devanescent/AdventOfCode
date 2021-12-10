#pragma once

namespace AdventOfCode::Year2020::Day17
{
	// 3D coords
	class CubeCoords
	{
	public:
		CubeCoords(int x, int y, int z) :
			X(x), Y(y), Z(z)
		{ }

		bool operator<(const CubeCoords& rhs) const
		{
			if (X != rhs.X)
				return X < rhs.X;
			else if (Y != rhs.Y)
				return Y < rhs.Y;
			else
				return Z < rhs.Z;
		}

		bool operator==(const CubeCoords& other) const
		{
			return X == other.X && Y == other.Y && Z == other.Z;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "Cube (%d, %d, %d)", X, Y, Z);
			return std::string(buf);
		}

		int	X;
		int	Y;
		int	Z;
	};
}