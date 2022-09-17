#pragma once
#include "InputProcessor.h"
#include "ComputationSample.h"

namespace AdventOfCode::Year2018::Day16
{
	class ComputationSampleProcessor : public InputProcessorBase<ComputationSample>
	{
	public:
		std::vector<ComputationSample> Process(std::vector<std::string> input) override;
	};
}