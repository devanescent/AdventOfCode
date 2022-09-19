#pragma once
#include "DayT.h"
#include "SpacetimeProcessor.h"

namespace AdventOfCode::Year2018::Day25
{
	// ---------------------------------------------------------------------------
	// Day25: Four-Dimensional Adventure
	// ---------------------------------------------------------------------------
	class FourDimensionalAdventure : public DayT<SpacetimeProcessor>
	{
	public:
		FourDimensionalAdventure();

		uint64_t ExecutePart1(std::vector<SpacetimeFixpoint> fixPoints) override;
		//uint64_t ExecutePart2(std::vector<Army> nanobots) override;
	};
}