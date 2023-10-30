#pragma once
#include "Day.h"

namespace AdventOfCode::Year2018::Day09
{
	// ---------------------------------------------------------------------------
	// Day09: Marble Mania 
	// ---------------------------------------------------------------------------
	class MarbleMania : public Day<>
	{
	public:
		MarbleMania();

	protected:
		uint64_t ExecutePart1(const std::vector<std::string> input) override;
		uint64_t ExecutePart2(const std::vector<std::string> input) override;
	};
}