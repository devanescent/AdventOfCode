#pragma once
#include "InputProcessorWithContext.h"
#include "MachinePart.h"
#include "Workflows.h"

namespace AdventOfCode::Year2023::Day19
{
	class WorkflowProcessor : public InputProcessorWithContextBase<MachinePart, std::vector<Workflow>>
	{
	public:
		std::pair<std::vector<MachinePart>, std::vector<Workflow>> Process(std::vector<std::string> input) override;
	};
}
