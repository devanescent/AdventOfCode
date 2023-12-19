#pragma once
#include "Day.h"

namespace AdventOfCode::Year2023::Day17
{
	// ---------------------------------------------------------------------------
	// Day17: Clumsy Crucible
	// ---------------------------------------------------------------------------
	class ClumsyCrucible : public Day<>
	{
	public:
		ClumsyCrucible();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> cityMap) override;
		uint64_t ExecutePart2(std::vector<std::string> cityMap) override;
	};
}
