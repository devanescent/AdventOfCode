#pragma once
#include "DayTC.h"
#include "GalaxyMapProcessor.h"

namespace AdventOfCode::Year2023::Day11
{
	// ---------------------------------------------------------------------------
	// Day11: Cosmic Expansion
	// ---------------------------------------------------------------------------
	class CosmicExpansion : public DayTC<GalaxyMapProcessor>
	{
	public:
		CosmicExpansion();

	protected:
		uint64_t ExecutePart1(std::vector<Point<uint64_t>> galaxies, SpaceExpansions expansions) override;
		uint64_t ExecutePart2(std::vector<Point<uint64_t>> galaxies, SpaceExpansions expansions) override;
	};
}
