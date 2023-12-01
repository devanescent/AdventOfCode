#pragma once
#include "Day.h"

namespace AdventOfCode::Year2023::Day01
{
	// ---------------------------------------------------------------------------
	// Day01: Trebuchet
	// ---------------------------------------------------------------------------
	class Trebuchet : public Day<>
	{
	public:
		Trebuchet();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;
	};
}
