#pragma once
#include "Day.h"

namespace AdventOfCode::Year2024::Day08
{
	// ---------------------------------------------------------------------------
	// Day08: Resonant Collinearity
	// ---------------------------------------------------------------------------
	class ResonantCollinearity : public Day<>
	{
	public:
		ResonantCollinearity();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;
	};
}
