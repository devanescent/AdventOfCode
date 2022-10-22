#pragma once

namespace AdventOfCode::Year2020::Day17
{
	// 3D coords
	class CubeCoords
	{
	public:
		CubeCoords(int x, int y, int z, int w = 0) :
			X(x), Y(y), Z(z), W(w)
		{ }

		bool operator<(const CubeCoords& rhs) const
		{
			if (X != rhs.X)
				return X < rhs.X;
			else if (Y != rhs.Y)
				return Y < rhs.Y;
			else if (Z != rhs.Z)
				return Z < rhs.Z;
			else
				return W < rhs.W;
		}

		bool operator==(const CubeCoords& other) const
		{
			return X == other.X && Y == other.Y && Z == other.Z && W == other.W;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "Cube (%d, %d, %d, %d)", X, Y, Z, W);
			return std::string(buf);
		}

		int	X;
		int	Y;
		int	Z;
		int W;
	};
}