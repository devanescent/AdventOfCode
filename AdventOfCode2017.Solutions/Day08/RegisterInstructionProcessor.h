#pragma once
#include "InputProcessor.h"
#include "RegisterInstruction.h"

namespace AdventOfCode::Year2017::Day08
{
	class RegisterInstructionProcessor : public InputProcessorBase<RegisterInstruction>
	{
	public:
		std::vector<RegisterInstruction> Process(std::vector<std::string> input) override;
	};
}
