#pragma once
#include "Day.h"

namespace AdventOfCode::Year2018::Day14
{
	// ---------------------------------------------------------------------------
	// Day20: Regular Map
	// ---------------------------------------------------------------------------
	class ChocolateCharts : public Day
	{
	public:
		ChocolateCharts();

		uint64_t GetResultOnPart1(const std::vector<std::string> input) override;
		uint64_t GetResultOnPart2(const std::vector<std::string> input) override;
	};
}