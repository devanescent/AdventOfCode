#pragma once
#include "Day.h"

namespace AdventOfCode::Year2022::Day17
{
	// ---------------------------------------------------------------------------
	// Day17: Pyroclastic Flow
	// ---------------------------------------------------------------------------
	class PyroclasticFlow : public Day<>
	{
	public:
		PyroclasticFlow();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> jets) override;
		uint64_t ExecutePart2(std::vector<std::string> jets) override;
	};
}
