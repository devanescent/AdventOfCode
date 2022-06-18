#pragma once
#include "DayT.h"
#include "GuardDutyRecordProcessor.h"

namespace AdventOfCode::Year2018::Day04
{
	// ---------------------------------------------------------------------------
	// Day04: Repose Record 
	// ---------------------------------------------------------------------------
	class ReposeRecord : public DayT<GuardDutyRecordProcessor>
	{
	public:
		ReposeRecord();
		uint64_t ExecutePart1(std::vector<std::unique_ptr<GuardDutyRecord>> records) override;
		uint64_t ExecutePart2(std::vector<std::unique_ptr<GuardDutyRecord>> records) override;
	};
}