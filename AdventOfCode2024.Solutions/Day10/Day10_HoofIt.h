#pragma once
#include "DayT.h"
#include "GridMapProcessor.h"

namespace AdventOfCode::Year2024::Day10
{
	// ---------------------------------------------------------------------------
	// Day10: Hoof It
	// ---------------------------------------------------------------------------
	class HoofIt : public DayT<GridMapProcessor>
	{
	public:
		HoofIt();

	protected:
		uint64_t ExecutePart1(GridMap map) override;
		uint64_t ExecutePart2(GridMap map) override;
	};
}
