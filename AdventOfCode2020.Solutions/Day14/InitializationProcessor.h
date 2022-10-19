#pragma once
#include "InputProcessor.h"
#include "InitializationInstruction.h"

namespace AdventOfCode::Year2020::Day14
{
	class InitializationProcessor : public InputProcessorBase<InitializationInstruction>
	{
	public:
		std::vector<InitializationInstruction> Process(std::vector<std::string> input) override;
	};
}


