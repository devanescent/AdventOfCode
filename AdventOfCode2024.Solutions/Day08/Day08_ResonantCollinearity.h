#pragma once
#include "DayT.h"
#include "GridMapProcessor.h"

namespace AdventOfCode::Year2024::Day08
{
	// ---------------------------------------------------------------------------
	// Day08: Resonant Collinearity
	// ---------------------------------------------------------------------------
	class ResonantCollinearity : public DayT<GridMapProcessor>
	{
	public:
		ResonantCollinearity();

	protected:
		uint64_t ExecutePart1(GridMap map) override;
		uint64_t ExecutePart2(GridMap map) override;
	};
}
