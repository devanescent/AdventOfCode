#include "Day11_CosmicExpansion.h"
#include <algorithm>

namespace AdventOfCode::Year2023::Day11
{
	CosmicExpansion::CosmicExpansion() : DayTC(11, "Cosmic Expansion") { }

	uint64_t SumGalaxyDistances(const std::vector<Point<uint64_t>>& galaxies)
	{
		// Sum up distances between all galaxies pairwise:
		uint64_t distanceSum = 0;
		for (int i = 0; i < galaxies.size() - 1; ++i)
		{
			for (int j = i + 1; j < galaxies.size(); ++j)
			{
				distanceSum += galaxies[i].DistanceTo(galaxies[j]);
			}
		}
		return distanceSum;
	}

	uint64_t CosmicExpansion::ExecutePart1(std::vector<Point<uint64_t>> galaxies, SpaceExpansions expansions)
	{
		// Apply expansions:
		std::for_each(galaxies.begin(), galaxies.end(),
			[&expansions](auto& galaxy) { expansions.ExpandGalaxy(galaxy, 2); });

		return SumGalaxyDistances(galaxies);
	}

	uint64_t CosmicExpansion::ExecutePart2(std::vector<Point<uint64_t>> galaxies, SpaceExpansions expansions)
	{
		// Apply expansions:
		std::for_each(galaxies.begin(), galaxies.end(),
			[&expansions](auto& galaxy) { expansions.ExpandGalaxy(galaxy, 1'000'000); });

		return SumGalaxyDistances(galaxies);
	}
}
