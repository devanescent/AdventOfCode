#pragma once
#include "DayT.h"
#include "GridMapProcessor.h"

namespace AdventOfCode::Year2024::Day06
{
	// ---------------------------------------------------------------------------
	// Day06: Guard Gallivant
	// ---------------------------------------------------------------------------
	class GuardGallivant : public DayT<GridMapProcessor>
	{
	public:
		GuardGallivant();

	protected:
		uint64_t ExecutePart1(GridMap map) override;
		uint64_t ExecutePart2(GridMap map) override;
	};
}
