#pragma once
#include "Day.h"

namespace AdventOfCode::Year2017::Day19
{
	// ---------------------------------------------------------------------------
	// Day19: A Series of Tubes
	// ---------------------------------------------------------------------------
	class ASeriesOfTubes : public Day
	{
	public:
		ASeriesOfTubes();

		uint64_t GetResultOnPart1(std::vector<std::string> input) override;
		uint64_t GetResultOnPart2(std::vector<std::string> input) override;
	};
}
