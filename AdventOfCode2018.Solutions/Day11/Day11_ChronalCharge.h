#pragma once
#include "Day.h"

namespace AdventOfCode::Year2018::Day11
{
	// ---------------------------------------------------------------------------
	// Day11: ChronalCharge 
	//  - Summed-area table: https://blog.demofox.org/2018/04/16/prefix-sums-and-summed-area-tables/
	// ---------------------------------------------------------------------------
	class ChronalCharge : public Day
	{
	public:
		ChronalCharge();
		uint64_t GetResultOnPart1(const std::vector<std::string> input) override;
	};
}