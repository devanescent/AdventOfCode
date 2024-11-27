#pragma once
#include "InputProcessor.h"
#include "RebootStep.h"

namespace AdventOfCode::Year2021::Day22
{
	class RebootStepProcessor : public InputProcessorBase<RebootStep>
	{
	public:
		std::vector<RebootStep> Process(std::vector<std::string> input) override;
	};
}