#pragma once
#include "Day.h"

namespace AdventOfCode::Year2022::Day12
{
	// ---------------------------------------------------------------------------
	// Day12: Hill Climbing Algorithm
	// ---------------------------------------------------------------------------
	class HillClimbingAlgorithm : public Day
	{
	public:
		HillClimbingAlgorithm();

		uint64_t GetResultOnPart1(std::vector<std::string> map) override;
		uint64_t GetResultOnPart2(std::vector<std::string> map) override;
	};
}
