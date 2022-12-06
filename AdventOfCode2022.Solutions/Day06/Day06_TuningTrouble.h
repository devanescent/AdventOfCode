#pragma once
#include "Day.h"

namespace AdventOfCode::Year2022::Day06
{
	// ---------------------------------------------------------------------------
	// Day06: Tuning Trouble
	// ---------------------------------------------------------------------------
	class TuningTrouble : public Day
	{
	public:
		TuningTrouble();

		uint64_t GetResultOnPart1(std::vector<std::string> input) override;
		uint64_t GetResultOnPart2(std::vector<std::string> input) override;
	};
}
