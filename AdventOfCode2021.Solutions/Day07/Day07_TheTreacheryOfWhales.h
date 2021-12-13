#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2021::Day07
{
	class TheTreacheryOfWhales : public DayT<int, IntProcessor<IntProcessingMode::ValuesAsSingleLine>>
	{
	public:
		TheTreacheryOfWhales();

	protected:
		uint64_t ExecutePart1(std::vector<int> crabPositions) override;
		uint64_t ExecutePart2(std::vector<int> crabPositions) override;
	};
}