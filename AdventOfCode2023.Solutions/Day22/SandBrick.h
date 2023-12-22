#pragma once

namespace AdventOfCode::Year2023::Day22
{
	class SandBrick
	{
	public:
		// To identify bricks easier
		int Num;

		int X1;
		int Y1;
		int Z1;

		int X2;
		int Y2;
		int Z2;

		bool operator<(const SandBrick& other) const
		{
			// Bricks closer to ground first:
			return Z1 < other.Z1;
		}

		bool operator>(const SandBrick& other) const
		{
			// Bricks higher-up first:
			return Z2 > other.Z2;
		}

		bool IsOnGround() const
		{
			return Z1 == 1 || Z2 == 1;
		}

		bool WillFallOnTopOf(const SandBrick& other) const
		{
			for (int xa = X1; xa <= X2; ++xa)
			{
				for (int ya = Y1; ya <= Y2; ++ya)
				{
					for (int xb = other.X1; xb <= other.X2; ++xb)
					{
						for (int yb = other.Y1; yb <= other.Y2; ++yb)
						{
							if (xa == xb && ya == yb)
								return true;
						}
					}
				}
			}

			return false;
		}
	};
}
