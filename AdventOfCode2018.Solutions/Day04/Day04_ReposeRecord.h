#pragma once
#include "DayT.h"
#include "GuardDutyRecordProcessor.h"

namespace AdventOfCode::Year2018::Day04
{
	// ---------------------------------------------------------------------------
	// Day01: ReportRepair 
	// ---------------------------------------------------------------------------
	class ReposeRecord : public DayT<GuardDutyRecordProcessor>
	{
	public:
		ReposeRecord();
		uint64_t ExecutePart1(std::vector<std::unique_ptr<GuardDutyRecord>> records) override;
		uint64_t ExecutePart2(std::vector<std::unique_ptr<GuardDutyRecord>> records) override;
	};
}