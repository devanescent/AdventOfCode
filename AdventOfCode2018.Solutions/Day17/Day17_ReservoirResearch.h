#pragma once
#include "DayT.h"
#include "ClayVeinProcessor.h"

namespace AdventOfCode::Year2018::Day17
{
	// ---------------------------------------------------------------------------
	// Day17: Reservoir Research
	// ---------------------------------------------------------------------------
	class ReservoirResearch : public DayT<ClayVeinProcessor>
	{
	public:
		ReservoirResearch();

		uint64_t ExecutePart1(std::vector<ClayVein> veins) override;
		uint64_t ExecutePart2(std::vector<ClayVein> veins) override;
	};
}