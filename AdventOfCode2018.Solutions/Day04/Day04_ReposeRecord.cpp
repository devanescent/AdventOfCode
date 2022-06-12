#include "Day04_ReposeRecord.h"

namespace AdventOfCode::Year2018::Day04
{
	ReposeRecord::ReposeRecord() : DayT(4, "Repose Record")
	{}

	uint64_t ReposeRecord::ExecutePart1(std::vector<std::unique_ptr<GuardDutyRecord>> records)
	{
		// Sort records by time:
		std::sort(records.begin(), records.end(), 
			[](const auto& ptr1, const auto& ptr2)
			{ return *ptr1 < *ptr2; }
		);

		// Process records to collect sleep periods:
		GuardSleepTimes sleepTimes;
		for (const std::unique_ptr<GuardDutyRecord>& record : records)
		{
			record->UpdateSleepTimes(sleepTimes);
		}

		// Process sleep records:
		return sleepTimes.FindMostAsleepGuard();
	}

	uint64_t ReposeRecord::ExecutePart2(std::vector<std::unique_ptr<GuardDutyRecord>> records)
	{
		// Sort records by time:
		std::sort(records.begin(), records.end(),
			[](const auto& ptr1, const auto& ptr2)
			{ return *ptr1 < *ptr2; }
		);

		// Process records to collect sleep periods:
		GuardSleepTimes sleepTimes;
		for (const std::unique_ptr<GuardDutyRecord>& record : records)
		{
			record->UpdateSleepTimes(sleepTimes);
		}

		// Process sleep records:
		return sleepTimes.FindMostAsleepMinute();
	}
}
