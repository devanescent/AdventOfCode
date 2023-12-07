#pragma once
#include "InputProcessor.h"
#include "PlayedCards.h"

namespace AdventOfCode::Year2023::Day07
{
	class CamelCardsProcessor : public InputProcessorBase<PlayedCards>
	{
	public:
		std::vector<PlayedCards> Process(std::vector<std::string> input) override;
	};
}
