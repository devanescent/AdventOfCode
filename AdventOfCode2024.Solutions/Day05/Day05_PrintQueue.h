#pragma once
#include "DayTC.h"
#include "PrintingRulesProcessor.h"

namespace AdventOfCode::Year2024::Day05
{
	// ---------------------------------------------------------------------------
	// Day05: Print Queue
	// ---------------------------------------------------------------------------
	class PrintQueue : public DayTC<PrintingRulesProcessor>
	{
	public:
		PrintQueue();

	protected:
		uint64_t ExecutePart1(std::vector<PageUpdate> updates, PageOrderingRules orderRules) override;
		uint64_t ExecutePart2(std::vector<PageUpdate> updates, PageOrderingRules orderRules) override;
	};
}
