#pragma once
#include "Day.h"

namespace AdventOfCode::Year2024::Day03
{
	// ---------------------------------------------------------------------------
	// Day03: Mull It Over
	// ---------------------------------------------------------------------------
	class MullItOver : public Day<>
	{
	public:
		MullItOver();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> program) override;
		uint64_t ExecutePart2(std::vector<std::string> program) override;
	};
}
