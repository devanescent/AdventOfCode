#pragma once
#include "Day.h"

namespace AdventOfCode::Year2022::Day12
{
	// ---------------------------------------------------------------------------
	// Day12: Hill Climbing Algorithm
	// ---------------------------------------------------------------------------
	class HillClimbingAlgorithm : public Day<>
	{
	public:
		HillClimbingAlgorithm();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> map) override;
		uint64_t ExecutePart2(std::vector<std::string> map) override;
	};
}
