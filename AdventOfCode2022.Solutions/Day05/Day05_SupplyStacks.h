#pragma once
#include "DayTC.h"
#include "CraneStepProcessor.h"

namespace AdventOfCode::Year2022::Day05
{
	// ---------------------------------------------------------------------------
	// Day05: Supply Stacks
	// ---------------------------------------------------------------------------
	class SupplyStacks : public DayTC<CraneStepProcessor>
	{
	public:
		SupplyStacks();

	protected:
		uint64_t ExecutePart1(std::vector<CraneStep> steps, CrateStacks stacks) override;
		uint64_t ExecutePart2(std::vector<CraneStep> steps, CrateStacks stacks) override;
	};
}
