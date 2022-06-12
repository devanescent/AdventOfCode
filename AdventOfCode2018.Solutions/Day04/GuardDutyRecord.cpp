#pragma once
#include <algorithm>
#include <map>
#include <numeric>
#include <vector>
#include "GuardDutyRecord.h"

namespace AdventOfCode::Year2018::Day04
{
	void BeginShiftRecord::UpdateSleepTimes(GuardSleepTimes & sleepTimes) const
	{
		sleepTimes.BeginShift(*this);
	}

	void SleepRecord::UpdateSleepTimes(GuardSleepTimes & sleepTimes) const
	{
		if (FellAsleep())
			sleepTimes.GuardFellAsleep(*this);
		else if (WokeUp())
			sleepTimes.GuardWokeUp(*this);
	}

	void GuardSleepTimes::BeginShift(const BeginShiftRecord & beginShiftRec)
	{
		m_lastShiftStartedGuard = beginShiftRec.GuardID();
	}

	void GuardSleepTimes::GuardFellAsleep(const SleepRecord & sleepRecord)
	{
		m_lastSleepBegan = sleepRecord.Minute();
	}

	void GuardSleepTimes::GuardWokeUp(const SleepRecord & sleepRecord)
	{
		for (int m = m_lastSleepBegan; m < sleepRecord.Minute(); ++m)
		{
			m_allSleepPeriods[m_lastShiftStartedGuard][m] += 1;
		}
	}

	uint64_t GuardSleepTimes::FindMostAsleepGuard()
	{
		// Aggregate sleep time for each guard:
		std::map<int, int> totalSleepTimes; // GuardID - totalSleepTime
		for (const auto& sleepPeriods : m_allSleepPeriods)
		{
			totalSleepTimes[sleepPeriods.first] = std::accumulate(sleepPeriods.second.begin(), sleepPeriods.second.end(), 0,
				[](int totalSleepTime, const std::pair<const int, int>& minuteOfSleep)
				{
					return totalSleepTime + minuteOfSleep.second;
				});
		}

		// Find guard that has been asleep the most:
		int maxAsleepGuard = std::max_element(totalSleepTimes.begin(), totalSleepTimes.end(),
			[](const auto& a, const auto& b)
			{
				return a.second < b.second;
			}
		)->first;

		// Find minute this guard was asleep the most:
		int minuteMaxAsleep = std::max_element(m_allSleepPeriods[maxAsleepGuard].begin(), m_allSleepPeriods[maxAsleepGuard].end(),
			[](const auto& a, const auto& b) { return a.second < b.second; }
		)->first;

		return maxAsleepGuard * minuteMaxAsleep;
	}

	uint64_t GuardSleepTimes::FindMostAsleepMinute()
	{
		// For each guard, find the minute he was asleep the most:
		std::vector<std::pair<int, int>> maxAsleepMinutes;

		std::transform(m_allSleepPeriods.begin(), m_allSleepPeriods.end(), std::back_inserter(maxAsleepMinutes),
			[](const auto& guardSleepPeriods)
			{
				return std::make_pair(
					guardSleepPeriods.first, 
					std::max_element(guardSleepPeriods.second.begin(), guardSleepPeriods.second.end(), 
						[](const auto& a, const auto& b) { return a.second < b.second; }
					)->first
				);
			}
		);

		// Find the maximum from this list again:
		auto maxSleepMinute = std::max_element(maxAsleepMinutes.begin(), maxAsleepMinutes.end(),
			[&](const auto& maxSleepMinute1, const auto& maxSleepMinute2)
			{
				return m_allSleepPeriods[maxSleepMinute1.first][maxSleepMinute1.second] <
						 m_allSleepPeriods[maxSleepMinute2.first][maxSleepMinute2.second];
			}
		);

		return maxSleepMinute->first * maxSleepMinute->second;
	}
}
