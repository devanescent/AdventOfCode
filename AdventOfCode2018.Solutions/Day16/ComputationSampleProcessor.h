#pragma once
#include "InputProcessorWithContext.h"
#include "ComputationSample.h"

namespace AdventOfCode::Year2018::Day16
{
	class ComputationSampleProcessor : public InputProcessorWithContextBase<ComputationSample, std::vector<Instruction>>
	{
	public:
		std::pair<std::vector<ComputationSample>, std::vector<Instruction>> Process(std::vector<std::string> input) override;
	};
}