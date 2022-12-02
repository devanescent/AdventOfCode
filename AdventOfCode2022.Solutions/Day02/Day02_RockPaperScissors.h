#pragma once
#include "DayT.h"
#include "StrategyGuideProcessor.h"

namespace AdventOfCode::Year2022::Day02
{
	// ---------------------------------------------------------------------------
	// Day02: Rock Paper Scissors
	// ---------------------------------------------------------------------------
	class RockPaperScissors : public DayT<StrategyGuideProcessor>
	{
	public:
		RockPaperScissors();

	protected:
		uint64_t ExecutePart1(std::vector<RockPaperScissorsRound> rounds) override;
		uint64_t ExecutePart2(std::vector<RockPaperScissorsRound> rounds) override;
	};
}
