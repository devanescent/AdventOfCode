#pragma once
#include "Day.h"

namespace AdventOfCode::Year2022::Day06
{
	// ---------------------------------------------------------------------------
	// Day06: Tuning Trouble
	// ---------------------------------------------------------------------------
	class TuningTrouble : public Day<>
	{
	public:
		TuningTrouble();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;
	};
}
