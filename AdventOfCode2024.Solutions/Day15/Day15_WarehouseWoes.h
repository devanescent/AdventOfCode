#pragma once
#include "DayTC.h"
#include "WarehouseProcessor.h"

namespace AdventOfCode::Year2024::Day15
{
	// ---------------------------------------------------------------------------
	// Day15: Warehouse Woes
	// ---------------------------------------------------------------------------
	class WarehouseWoes : public DayTC<WarehouseProcessor>
	{
	public:
		WarehouseWoes();

	protected:
		uint64_t ExecutePart1(std::vector<Point<int>> movements, GridMap context) override;
		uint64_t ExecutePart2(std::vector<Point<int>> movements, GridMap context) override;
	};
}
