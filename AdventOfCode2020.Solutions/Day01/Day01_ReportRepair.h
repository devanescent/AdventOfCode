#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2020::Day01
{
	// ---------------------------------------------------------------------------
	// Day01: ReportRepair 
	// ---------------------------------------------------------------------------
	class ReportRepair : public DayT<IntProcessor<IntProcessingMode::ValuePerLine>>
	{
	public:
		ReportRepair();

	protected:
		uint64_t ExecutePart1(std::vector<int> report) override;
		uint64_t ExecutePart2(std::vector<int> report) override;
	};
}