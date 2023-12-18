#pragma once
#include "InputProcessor.h"
#include "DigPlan.h"

namespace AdventOfCode::Year2023::Day18
{
	class DigPlanProcessor : public InputProcessorBase<DigPlan>
	{
	public:
		std::vector<DigPlan> Process(std::vector<std::string> input) override;
	};
}
