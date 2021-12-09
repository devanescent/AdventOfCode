#pragma once
#include "DayT.h"
#include "HeatMapProcessor.h"

namespace AdventOfCode::Year2021::Day09
{
	class SmokeBasin : public DayT<std::vector<HeatMapNode>, HeatMapProcessor>
	{
	public:
		SmokeBasin();

	protected:
		uint64_t ExecutePart1(std::vector<std::vector<HeatMapNode>> heatMap) override;
	};
}