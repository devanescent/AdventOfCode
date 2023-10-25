#pragma once
#include "DayTC.h"
#include "BlueprintsProcessor.h"

namespace AdventOfCode::Year2017::Day25
{
	// ---------------------------------------------------------------------------
	// Day25: The Halting Problem
	// ---------------------------------------------------------------------------
	class TheHaltingProblem : public DayTC<BlueprintsProcessor>
	{
	public:
		TheHaltingProblem();

	protected:
		uint64_t ExecutePart1(std::vector<Blueprint> blueprints, BlueprintInitializer context) override;
		uint64_t ExecutePart2(std::vector<Blueprint> blueprints, BlueprintInitializer context) override;
	};
}
