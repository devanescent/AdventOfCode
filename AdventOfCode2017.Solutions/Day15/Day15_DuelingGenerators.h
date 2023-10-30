#pragma once
#include "Day.h"

namespace AdventOfCode::Year2017::Day15
{
	// ---------------------------------------------------------------------------
	// Day15: Dueling Generators
	// ---------------------------------------------------------------------------
	class DuelingGenerators : public Day<>
	{
	public:
		DuelingGenerators();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;
	};
}
