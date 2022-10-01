#pragma once
#include "InputProcessor.h"

namespace AdventOfCode::Year2020::Day05
{
	class BoardingPassProcessor : public InputProcessorBase<int>
	{
	public:
		std::vector<int> Process(std::vector<std::string> boardingPasses) override;
	};
}

