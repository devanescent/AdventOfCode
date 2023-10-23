#pragma once
#include "Day.h"

namespace AdventOfCode::Year2017::Day17
{
	// ---------------------------------------------------------------------------
	// Day17: Spinlock
	// ---------------------------------------------------------------------------
	class Spinlock : public Day
	{
	public:
		Spinlock();

		uint64_t GetResultOnPart1(std::vector<std::string> input) override;
		uint64_t GetResultOnPart2(std::vector<std::string> input) override;
	};
}
