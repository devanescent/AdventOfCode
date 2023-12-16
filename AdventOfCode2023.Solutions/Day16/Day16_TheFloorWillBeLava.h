#pragma once
#include "Day.h"

namespace AdventOfCode::Year2023::Day16
{
	// ---------------------------------------------------------------------------
	// Day16: The Floor Will Be Lava
	// ---------------------------------------------------------------------------
	class TheFloorWillBeLava : public Day<>
	{
	public:
		TheFloorWillBeLava();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> caveMap) override;
		uint64_t ExecutePart2(std::vector<std::string> caveMap) override;
	};
}
