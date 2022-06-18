#pragma once
#include "Day.h"

namespace AdventOfCode::Year2018::Day09
{
	// ---------------------------------------------------------------------------
	// Day09: Marble Mania 
	// ---------------------------------------------------------------------------
	class MarbleMania : public Day
	{
	public:
		MarbleMania();
		uint64_t GetResultOnPart1(const std::vector<std::string> input) override;
	};
}