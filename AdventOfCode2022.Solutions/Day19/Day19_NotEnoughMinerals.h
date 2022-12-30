#pragma once
#include "DayT.h"
#include "BlueprintProcessor.h"

namespace AdventOfCode::Year2022::Day19
{
	// ---------------------------------------------------------------------------
	// Day19: Not Enough Minerals
	// ---------------------------------------------------------------------------
	class NotEnoughMinerals : public DayT<BlueprintProcessor>
	{
	public:
		NotEnoughMinerals();

	protected:
		uint64_t ExecutePart1(std::vector<Blueprint> blueprints) override;
		uint64_t ExecutePart2(std::vector<Blueprint> blueprints) override;
	};
}
