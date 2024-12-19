#pragma once
#include "DayTC.h"
#include "TowelPatternProcessor.h"

namespace AdventOfCode::Year2024::Day19
{
	// ---------------------------------------------------------------------------
	// Day19: Linen Layout
	// ---------------------------------------------------------------------------
	class LinenLayout : public DayTC<TowelPatternProcessor>
	{
	public:
		LinenLayout();

	protected:
		uint64_t ExecutePart1(std::vector<DisplayDesign> displayDesigns, TowelPatterns patterns) override;
		uint64_t ExecutePart2(std::vector<DisplayDesign> displayDesigns, TowelPatterns patterns) override;
	};
}
