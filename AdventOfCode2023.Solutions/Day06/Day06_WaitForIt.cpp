#include "Day06_WaitForIt.h"
#include <numeric>

namespace AdventOfCode::Year2023::Day06
{
	WaitForIt::WaitForIt() : DayT(6, "Wait For It") { }

	uint64_t WaitForIt::ExecutePart1(std::vector<RaceRecord> raceRecords)
	{
		return std::accumulate(raceRecords.begin(), raceRecords.end(), 1ull,
			[](uint64_t result, const RaceRecord& record)
			{
				// Try all combinations:
				uint64_t wins = 0;
				for (int t = 1; t < record.Time; ++t)
				{
					int distance = (record.Time - t) * t;
					if (distance > record.Distance)
						++wins;
				}

				// Multiply together:
				return result * wins;
			});
	}

	uint64_t WaitForIt::ExecutePart2(std::vector<RaceRecord> raceRecords)
	{
		// Combine records into single time / distance entry:
		std::string totalTimeStr = std::accumulate(raceRecords.begin(), raceRecords.end(), std::string(),
			[](std::string combinedTime, const RaceRecord& record)
			{ return combinedTime + std::to_string(record.Time); });
		
		std::string totalDistanceStr = std::accumulate(raceRecords.begin(), raceRecords.end(), std::string(),
			[](std::string combinedDistance, const RaceRecord& record)
			{ return combinedDistance + std::to_string(record.Distance); });
		
		uint64_t totalTime = std::stoull(totalTimeStr);
		uint64_t totalDistance = std::stoull(totalDistanceStr);

		// Try all combinations:
		uint64_t wins = 0;
		for (int t = 1; t < totalTime; ++t)
		{
			uint64_t distance = (totalTime - t) * t;
			if (distance > totalDistance)
				++wins;
		}

		return wins;
	}
}
