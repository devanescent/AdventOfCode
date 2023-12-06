#pragma once
#include "DayT.h"
#include "RaceRecordsProcessor.h"

namespace AdventOfCode::Year2023::Day06
{
	// ---------------------------------------------------------------------------
	// Day06: Wait For It
	// ---------------------------------------------------------------------------
	class WaitForIt : public DayT<RaceRecordsProcessor>
	{
	public:
		WaitForIt();

	protected:
		uint64_t ExecutePart1(std::vector<RaceRecord> raceRecords) override;
		uint64_t ExecutePart2(std::vector<RaceRecord> raceRecords) override;
	};
}
