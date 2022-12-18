#pragma once
#include "DayT.h"
#include "CubeProcessor.h"

namespace AdventOfCode::Year2022::Day18
{
	// ---------------------------------------------------------------------------
	// Day18: Boiling Boulders
	// ---------------------------------------------------------------------------
	class BoilingBoulders : public DayT<CubeProcessor>
	{
	public:
		BoilingBoulders();

	protected:
		uint64_t ExecutePart1(std::vector<Cube> cubes) override;
		uint64_t ExecutePart2(std::vector<Cube> cubes) override;
	};
}
