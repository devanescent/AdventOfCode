#pragma once
#include "InputProcessor.h"
#include "PulseModule.h"

namespace AdventOfCode::Year2023::Day20
{
	class PulseModuleProcessor : public InputProcessorBase<PulseModule>
	{
	public:
		std::vector<PulseModule> Process(std::vector<std::string> input) override;
	};
}
