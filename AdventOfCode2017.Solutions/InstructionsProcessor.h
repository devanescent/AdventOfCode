﻿#pragma once
#include "InputProcessor.h"
#include "Instruction.h"

namespace AdventOfCode::Year2017
{
	class InstructionsProcessor : public InputProcessorBase<Instruction>
	{
	public:
		std::vector<Instruction> Process(std::vector<std::string> input) override;
	};
}
