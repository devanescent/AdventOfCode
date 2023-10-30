#include "Day17_TrickShot.h"
#include <regex>

namespace AdventOfCode::Year2021::Day17
{
	TrickShot::TrickShot() : Day(17, "Trick Shot") {}

	// ---------------------------------------------------------------------------
	// Part 1:
	// ---------------------------------------------------------------------------
	uint64_t TrickShot::ExecutePart1(const std::vector<std::string> input)
	{
		int targetXMin = 0, targetXMax = 0, targetYMin = 0, targetYMax = 0;
		sscanf_s(input[0].c_str(), "target area: x=%d..%d, y=%d..%d", &targetXMin, &targetXMax, &targetYMin, &targetYMax);

		// Target area must not pass through y = 0 (otherwise max velocity would be infinity)
		uint64_t maxVelo = 0;
		if (targetYMin > 0)
		{
			// Target area above the start pos:
			// The starting velocity can be max. the upper limit of the target area:
			maxVelo = targetYMax;
		}
		else if (targetYMax < 0)
		{
			// Target area below the start pos:
			// After falling down, the downward velocity at the zero line will have the same value as the starting velocity
			// At the next step, due to gravity, it will have increased by one
			maxVelo = std::abs(targetYMin) - 1;
		}

		// The maximum height reached is maxVelo + (maxVelo - 1) + (maxVelo - 2) + ... -> Gauss sum:
		return maxVelo * (maxVelo + 1) / 2;
	}
}
