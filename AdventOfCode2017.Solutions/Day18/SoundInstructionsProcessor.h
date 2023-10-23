#pragma once
#include "InputProcessor.h"
#include "SoundInstruction.h"

namespace AdventOfCode::Year2017::Day18
{
	class SoundInstructionsProcessor : public InputProcessorBase<SoundInstruction>
	{
	public:
		std::vector<SoundInstruction> Process(std::vector<std::string> input) override;
	};
}
