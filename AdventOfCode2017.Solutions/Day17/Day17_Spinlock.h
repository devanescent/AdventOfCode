#pragma once
#include "Day.h"

namespace AdventOfCode::Year2017::Day17
{
	// ---------------------------------------------------------------------------
	// Day17: Spinlock
	// ---------------------------------------------------------------------------
	class Spinlock : public Day<>
	{
	public:
		Spinlock();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;
	};
}
