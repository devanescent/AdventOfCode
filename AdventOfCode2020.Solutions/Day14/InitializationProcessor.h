#pragma once
#include "InputProcessorWithContext.h"
#include "InitializationInstruction.h"

namespace AdventOfCode::Year2020::Day14
{
	class InitializationProcessor : public InputProcessorWithContextBase<InitializationInstruction, InitializationContext>
	{
	public:
		std::pair<std::vector<InitializationInstruction>, InitializationContext> Process(std::vector<std::string> input) override;
	};
}


