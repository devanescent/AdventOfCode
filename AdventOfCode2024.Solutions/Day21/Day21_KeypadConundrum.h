#pragma once
#include "Day.h"

namespace AdventOfCode::Year2024::Day21
{
	// ---------------------------------------------------------------------------
	// Day21: Keypad Conundrum
	// ---------------------------------------------------------------------------
	class KeypadConundrum : public Day<>
	{
	public:
		KeypadConundrum();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> keycodes) override;
		uint64_t ExecutePart2(std::vector<std::string> keycodes) override;
	};
}
