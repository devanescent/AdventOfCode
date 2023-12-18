#pragma once
#include "DayT.h"
#include "DigPlanProcessor.h"

namespace AdventOfCode::Year2023::Day18
{
	// ---------------------------------------------------------------------------
	// Day18: Lavaduct Lagoon
	// ---------------------------------------------------------------------------
	class LavaductLagoon : public DayT<DigPlanProcessor>
	{
	public:
		LavaductLagoon();

	protected:
		uint64_t ExecutePart1(std::vector<DigPlan> digPlans) override;
		uint64_t ExecutePart2(std::vector<DigPlan> digPlans) override;
	};
}
