#pragma once
#include "InputProcessor.h"
#include "Scratchcard.h"

namespace AdventOfCode::Year2023::Day04
{
	class ScratchcardProcessor : public InputProcessorBase<Scratchcard>
	{
	public:
		std::vector<Scratchcard> Process(std::vector<std::string> input) override;
	};
}
