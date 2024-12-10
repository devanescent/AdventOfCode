#pragma once
#include "Day.h"

namespace AdventOfCode::Year2024::Day10
{
	// ---------------------------------------------------------------------------
	// Day10: Hoof It
	// ---------------------------------------------------------------------------
	class HoofIt : public Day<>
	{
	public:
		HoofIt();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;
	};
}
