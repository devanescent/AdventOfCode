#pragma once
#include "InputProcessor.h"

namespace AdventOfCode::Year2023::Day15
{
	class InitSequenceProcessor : public InputProcessorBase<std::string>
	{
	public:
		std::vector<std::string> Process(std::vector<std::string> input) override;
	};
}
