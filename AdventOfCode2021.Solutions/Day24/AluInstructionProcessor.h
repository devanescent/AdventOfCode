#pragma once
#include "InputProcessor.h"
#include "AluInstruction.h"

namespace AdventOfCode::Year2021::Day24
{
	class AluInstructionProcessor : public InputProcessorBase<AluInstruction>
	{
	public:
		std::vector<AluInstruction> Process(std::vector<std::string> input) override;
	};
}
