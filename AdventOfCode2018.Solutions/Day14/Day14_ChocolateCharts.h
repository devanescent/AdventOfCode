#pragma once
#include "Day.h"

namespace AdventOfCode::Year2018::Day14
{
	// ---------------------------------------------------------------------------
	// Day20: Regular Map
	// ---------------------------------------------------------------------------
	class ChocolateCharts : public Day<>
	{
	public:
		ChocolateCharts();

	protected:
		uint64_t ExecutePart1(const std::vector<std::string> input) override;
		uint64_t ExecutePart2(const std::vector<std::string> input) override;
	};
}