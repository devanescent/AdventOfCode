#pragma once
#include "Day.h"

namespace AdventOfCode::Year2024::Day06
{
	// ---------------------------------------------------------------------------
	// Day06: Guard Gallivant
	// ---------------------------------------------------------------------------
	class GuardGallivant : public Day<>
	{
	public:
		GuardGallivant();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;
	};
}
