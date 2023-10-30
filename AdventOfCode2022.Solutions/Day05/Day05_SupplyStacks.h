#pragma once
#include "DayTC.h"
#include "CraneStepProcessor.h"

namespace AdventOfCode::Year2022::Day05
{
	// ---------------------------------------------------------------------------
	// Day05: Supply Stacks
	// ---------------------------------------------------------------------------
	class SupplyStacks : public DayTC<CraneStepProcessor, std::string>
	{
	public:
		SupplyStacks();

	protected:
		std::string ExecutePart1(std::vector<CraneStep> steps, CrateStacks stacks) override;
		std::string ExecutePart2(std::vector<CraneStep> steps, CrateStacks stacks) override;
	};
}
