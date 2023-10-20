#pragma once
#include "Day.h"

namespace AdventOfCode::Year2017::Day15
{
	// ---------------------------------------------------------------------------
	// Day15: Dueling Generators
	// ---------------------------------------------------------------------------
	class DuelingGenerators : public Day
	{
	public:
		DuelingGenerators();

		uint64_t GetResultOnPart1(std::vector<std::string> input) override;
		uint64_t GetResultOnPart2(std::vector<std::string> input) override;
	};
}
