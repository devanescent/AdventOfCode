#pragma once
#include "InputProcessor.h"
#include "AssemblyStep.h"

namespace AdventOfCode::Year2018::Day07
{
	class AssemblyStepsProcessor : public InputProcessorBase<AssemblyStep>
	{
	public:
		std::vector<AssemblyStep> Process(std::vector<std::string> input) override;
	};
}