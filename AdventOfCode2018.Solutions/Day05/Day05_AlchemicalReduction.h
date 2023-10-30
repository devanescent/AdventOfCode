#pragma once
#include "Day.h"

namespace AdventOfCode::Year2018::Day05
{
	// ---------------------------------------------------------------------------
	// Day05: Alchemical Reduction 
	// ---------------------------------------------------------------------------
	class AlchemicalReduction : public Day<>
	{
	public:
		AlchemicalReduction();

	protected:
		uint64_t ExecutePart1(const std::vector<std::string> input) override;
		uint64_t ExecutePart2(const std::vector<std::string> input) override;
	};
}