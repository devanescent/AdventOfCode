#pragma once
#include "DayT.h"
#include "GridMapProcessor.h"

namespace AdventOfCode::Year2024::Day12
{
	// ---------------------------------------------------------------------------
	// Day12: Garden Groups
	// ---------------------------------------------------------------------------
	class GardenGroups : public DayT<GridMapProcessor>
	{
	public:
		GardenGroups();

	protected:
		uint64_t ExecutePart1(GridMap gardenMap) override;
		uint64_t ExecutePart2(GridMap gardenMap) override;
	};
}
