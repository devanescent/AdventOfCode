#pragma once
#include "Day.h"

namespace AdventOfCode::Year2024::Day04
{
	// ---------------------------------------------------------------------------
	// Day04: Ceres Search
	// ---------------------------------------------------------------------------
	class CeresSearch : public Day<>
	{
	public:
		CeresSearch();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;
	};
}
