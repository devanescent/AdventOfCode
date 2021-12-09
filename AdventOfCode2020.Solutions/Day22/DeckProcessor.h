#pragma once
#include "InputProcessor.h"
#include "Deck.h"

namespace AdventOfCode::Year2020::Day22
{
	class DeckProcessor : public InputProcessorBase<Deck>
	{
	public:
		std::vector<Deck> Process(std::vector<std::string> input) override;
	};

}
