#pragma once
#include "InputProcessor.h"
#include "NavInstruction.h"

namespace AdventOfCode::Year2020::Day12
{
	class NavInstructionProcessor : public InputProcessorBase<NavInstruction>
	{
	public:
		std::vector<NavInstruction> Process(std::vector<std::string> input) override;
	};
}


