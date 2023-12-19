#pragma once
#include "DayTC.h"
#include "WorkflowProcessor.h"

namespace AdventOfCode::Year2023::Day19
{
	// ---------------------------------------------------------------------------
	// Day19: Aplenty
	// ---------------------------------------------------------------------------
	class Aplenty : public DayTC<WorkflowProcessor>
	{
	public:
		Aplenty();

	protected:
		uint64_t ExecutePart1(std::vector<MachinePart> machineParts, std::vector<Workflow> workflows) override;
		uint64_t ExecutePart2(std::vector<MachinePart> machineParts, std::vector<Workflow> workflows) override;
	};
}
