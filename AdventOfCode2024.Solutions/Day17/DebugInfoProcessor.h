#pragma once
#include "InputProcessorWithContext.h"
#include "OpCode.h"
#include "Registers.h"

namespace AdventOfCode::Year2024::Day17
{
	class DebugInfoProcessor : public InputProcessorWithContextBase<int, Registers>
	{
	public:
		std::pair<std::vector<int>, Registers> Process(std::vector<std::string> input) override;
	};
}
