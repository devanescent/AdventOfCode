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
		uint64_t ExecutePart1(HeatMap heatMap) override;
		uint64_t ExecutePart2(HeatMap heatMap) override;

	private:
		int GetBasinSize(HeatMap& map, int x, int y);
	};
}