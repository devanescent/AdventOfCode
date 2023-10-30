#pragma once
#include "Day.h"

namespace AdventOfCode::Year2022::Day08
{
	// ---------------------------------------------------------------------------
	// Day08: Treetop Tree House
	// ---------------------------------------------------------------------------
	class TreetopTreeHouse : public Day<>
	{
	public:
		TreetopTreeHouse();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;
	};
}
