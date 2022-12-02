#pragma once
#include "InputProcessor.h"
#include "RockPaperScissorsRound.h"

namespace AdventOfCode::Year2022::Day02
{
	class StrategyGuideProcessor : public InputProcessorBase<RockPaperScissorsRound>
	{
	public:
		std::vector<RockPaperScissorsRound> Process(std::vector<std::string> input) override;
	};
}
