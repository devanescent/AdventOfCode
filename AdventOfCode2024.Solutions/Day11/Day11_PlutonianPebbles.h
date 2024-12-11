#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2024::Day11
{
	// ---------------------------------------------------------------------------
	// Day11: Plutonian Pebbles
	// ---------------------------------------------------------------------------
	class PlutonianPebbles : public DayT<IntProcessor<IntProcessingMode::ValuesAsSpaceSeparatedLine>>
	{
	public:
		PlutonianPebbles();

	protected:
		uint64_t ExecutePart1(std::vector<int> stones) override;
		uint64_t ExecutePart2(std::vector<int> stones) override;
	};
}
