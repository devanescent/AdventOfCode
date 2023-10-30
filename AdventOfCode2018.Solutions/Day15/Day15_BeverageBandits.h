#pragma once
#include "Day.h"

namespace AdventOfCode::Year2018::Day15
{
	// ---------------------------------------------------------------------------
	// Day15: Beverage Bandits
	// ---------------------------------------------------------------------------
	class BeverageBandits : public Day<>
	{
	public:
		BeverageBandits();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> map) override;
		uint64_t ExecutePart2(std::vector<std::string> map) override;
	};
}