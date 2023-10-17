 #pragma once
#include "InputProcessor.h"

namespace AdventOfCode::Year2017::Day02
{
	class SpreadsheetProcessor : public InputProcessorBase<std::vector<int>>
	{
	public:
		std::vector<std::vector<int>> Process(std::vector<std::string> input) override;
	};
}
