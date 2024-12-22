#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2024::Day22
{
	// ---------------------------------------------------------------------------
	// Day22: Monkey Market
	// ---------------------------------------------------------------------------
	class MonkeyMarket : public DayT<IntProcessor<IntProcessingMode::ValuePerLine>>
	{
	public:
		MonkeyMarket();

	protected:
		uint64_t ExecutePart1(std::vector<int> secretNumbers) override;
		uint64_t ExecutePart2(std::vector<int> secretNumbers) override;
	};
}
