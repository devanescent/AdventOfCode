#pragma once
#include "Day.h"

namespace AdventOfCode::Year2023::Day23
{
	// ---------------------------------------------------------------------------
	// Day23: A Long Walk
	// ---------------------------------------------------------------------------
	class ALongWalk : public Day<>
	{
	public:
		ALongWalk();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> hikingTrails) override;
		uint64_t ExecutePart2(std::vector<std::string> hikingTrails) override;
	};
}
