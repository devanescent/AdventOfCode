#pragma once
#include "Day.h"

namespace AdventOfCode::Year2018::Day05
{
	// ---------------------------------------------------------------------------
	// Day01: ReportRepair 
	// ---------------------------------------------------------------------------
	class AlchemicalReduction : public Day
	{
	public:
		AlchemicalReduction();

		uint64_t GetResultOnPart1(const std::vector<std::string> input) override;
		uint64_t GetResultOnPart2(const std::vector<std::string> input) override;
	};
}