#pragma once
#include "InputProcessor.h"
#include "InstructionStep.h"

namespace AdventOfCode::Year2018::Day07
{
	class InstructionProcessor : public InputProcessorBase<InstructionStep>
	{
	public:
		std::vector<InstructionStep> Process(std::vector<std::string> input) override;
	};
}