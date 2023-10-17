#pragma once
#include "Day.h"

namespace AdventOfCode::Year2017::Day03
{
	// ---------------------------------------------------------------------------
	// Day03: Spiral Memory
	// ---------------------------------------------------------------------------
	class SpiralMemory : public Day
	{
	public:
		SpiralMemory();

		uint64_t GetResultOnPart1(std::vector<std::string> input) override;
		uint64_t GetResultOnPart2(std::vector<std::string> input) override;
	};

	enum class Direction
	{
		Up,
		Left,
		Down,
		Right
	};
}
