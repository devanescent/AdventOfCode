#include "Day17_TrickShot.h"
#include "Point.h"
#include <regex>

namespace AdventOfCode::Year2021::Day17
{
	TrickShot::TrickShot() : Day(17, "Trick Shot") {}

	// ---------------------------------------------------------------------------
	// Part 1:
	// ---------------------------------------------------------------------------
	uint64_t TrickShot::ExecutePart1(const std::vector<std::string> input)
	{
		int targetXStart = 0, targetXEnd = 0, targetYStart = 0, targetYEnd = 0;
		sscanf_s(input[0].c_str(), "target area: x=%d..%d, y=%d..%d", &targetXStart, &targetXEnd, &targetYEnd, &targetYStart);

		// Assume target area is always below y=0
		// 
		// After falling down, the downward velocity at the zero line will
		// have the same value as the starting velocity.
		// At the next step, due to gravity, it will have increased by one,
		// so it has to be one unit smaller to not overshoot the target area.
		auto vy_max = std::abs(targetYEnd) - 1;

		// The maximum height reached is maxVelo + (maxVelo - 1) + (maxVelo - 2) + ... -> Gauss. sum:
		return vy_max * (vy_max + 1) / 2;
	}

	// ---------------------------------------------------------------------------
	// Part 2:
	// ---------------------------------------------------------------------------
	uint64_t TrickShot::ExecutePart2(const std::vector<std::string> input)
	{
		int targetXStart = 0, targetXEnd = 0, targetYStart = 0, targetYEnd = 0;
		sscanf_s(input[0].c_str(), "target area: x=%d..%d, y=%d..%d", &targetXStart, &targetXEnd, &targetYEnd, &targetYStart);

		// Find limits for vx/vy:

		// Lowest value for vy will be directly shooting at the target area without overshooting it:
		// Highest value from part 1:
		int64_t vy_min = targetYEnd;
		int64_t vy_max = ExecutePart1(input);

		// vx will always be positive values:
		// Lowest value for vx is when the target area will be barely reached:
		//			vx * (vx + 1) / 2 = targetXStart
		// <=>	vx^2 + vx - 2*targetXStart = 0
		// <=>	vx = -1/2 + sqrt(1/4 + 2*targetXStart) (only positive solution)
		int64_t vx_min = std::ceill(-0.5 + sqrt(0.25 + 2 * targetXStart));
		int64_t vx_max = targetXEnd;

		uint64_t validVelocities = 0;
		for (auto vx = vx_min; vx <= vx_max; ++vx)
		{
			for (auto vy = vy_min; vy <= vy_max; ++vy)
			{
				// 23,-10
				if (vx == 23 && vy == -10)
				{
					int halt = 0;
				}

				Point<int64_t> v(vx, vy);
				Point<int64_t> pos(0, 0);
				while (pos.X <= targetXEnd && pos.Y >= targetYEnd)
				{
					pos.X += v.X;
					pos.Y += v.Y;

					if (pos.IsXBetween(targetXStart, targetXEnd) && pos.IsYBetween(targetYEnd, targetYStart))
					{
						++validVelocities;
						break;
					}

					if (v.X > 0) --v.X;
					--v.Y;
				}
			}
		}

		return validVelocities;
	}
}
