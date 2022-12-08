#pragma once
#include "Day.h"

namespace AdventOfCode::Year2022::Day08
{
	// ---------------------------------------------------------------------------
	// Day08: Treetop Tree House
	// ---------------------------------------------------------------------------
	class TreetopTreeHouse : public Day
	{
	public:
		TreetopTreeHouse();

		uint64_t GetResultOnPart1(std::vector<std::string> input) override;
		uint64_t GetResultOnPart2(std::vector<std::string> input) override;
	};
}
