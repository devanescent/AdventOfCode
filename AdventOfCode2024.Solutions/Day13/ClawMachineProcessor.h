#pragma once
#include "InputProcessor.h"
#include "ClawMachine.h"

namespace AdventOfCode::Year2024::Day13
{
	class ClawMachineProcessor : public InputProcessorBase<ClawMachine>
	{
	public:
		std::vector<ClawMachine> Process(std::vector<std::string> input) override;
	};
}
