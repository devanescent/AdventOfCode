#pragma once
#include "InputProcessor.h"
#include "Instruction.h"

namespace AdventOfCode::Year2020::Day08
{
	class InstructionProcessor : public InputProcessorBase<Instruction>
	{
	public:
		std::vector<Instruction> Process(std::vector<std::string> input) override;
	};
}

