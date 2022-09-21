#pragma once
#include "InputProcessorWithContext.h"
#include "..\Day16\Instruction.h"

namespace AdventOfCode::Year2018::Day19
{
	// Reuse Instruction class from Day 16:
	using Instruction = AdventOfCode::Year2018::Day16::Instruction;


	class InstructionProcessor : public InputProcessorWithContextBase<Instruction, int>
	{
	public:
		std::pair<std::vector<Instruction>, int> Process(std::vector<std::string> input) override;
	};
}