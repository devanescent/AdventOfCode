#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2018::Day01
{
	// ---------------------------------------------------------------------------
	// Day01: ReportRepair 
	// ---------------------------------------------------------------------------
	class ChronalCalibration : public DayT<IntProcessor<IntProcessingMode::ValuePerLine>>
	{
	public:
		ChronalCalibration();

	protected:
		uint64_t ExecutePart1(std::vector<int> report) override;
		uint64_t ExecutePart2(std::vector<int> report) override;
	};
}