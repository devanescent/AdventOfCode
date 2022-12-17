#pragma once
#include "Day.h"

namespace AdventOfCode::Year2022::Day17
{
	// ---------------------------------------------------------------------------
	// Day17: Pyroclastic Flow
	// ---------------------------------------------------------------------------
	class PyroclasticFlow : public Day
	{
	public:
		PyroclasticFlow();

		uint64_t GetResultOnPart1(std::vector<std::string> jets) override;
		uint64_t GetResultOnPart2(std::vector<std::string> jets) override;
	};
}
