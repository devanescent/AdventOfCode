#include "Day07_TheTreacheryOfWhales.h"
#include <algorithm>
#include <numeric>
#include <map>

namespace AdventOfCode::Year2021::Day07
{
	TheTreacheryOfWhales::TheTreacheryOfWhales() : DayT(7, "The Treachery of Whales") {}

	std::map<int, uint64_t> UpdateFishCounts(std::map<int, uint64_t> fishCounts)
	{
		std::map<int, uint64_t> newFishCounts;
		for (auto& fishEntry : fishCounts)
		{
			if (fishEntry.first > 0)
				newFishCounts[fishEntry.first - 1] += fishEntry.second;
			else
			{
				newFishCounts[6] += fishEntry.second;
				newFishCounts[8] = fishEntry.second;
			}
		}
		return newFishCounts;
	}

	/// <summary>
	/// Executes part 1 of the day 07 challenge
	/// </summary>
	uint64_t TheTreacheryOfWhales::ExecutePart1(std::vector<int> crabPositions)
	{
		// Find the median as the position for which the sum of all distances for all the other crabs is minimized
		int median = 0;
		size_t middlePos = crabPositions.size() / 2;
		

		if (crabPositions.size() % 2 == 1)
		{
			// odd number of elements: median is the middle element
			std::nth_element(crabPositions.begin(), crabPositions.begin() + middlePos, crabPositions.end());
			median = crabPositions[middlePos];
		}
		else
		{
			// even number of elements: median is the average of the two middle elements:
			std::nth_element(crabPositions.begin(), crabPositions.begin() + middlePos, crabPositions.end());
			std::nth_element(crabPositions.begin(), crabPositions.begin() + (middlePos - 1), crabPositions.end());
			median = (crabPositions[middlePos - 1] + crabPositions[middlePos]) / 2;
		}

		// Calculate the total amount of fuel spent (=the distance to the median) for all crabs:
		return std::accumulate(crabPositions.begin(), crabPositions.end(), 0ull,
			[median](uint64_t fuelSpent, int crabPos)
			{
				return fuelSpent + std::abs(crabPos - median);
			}
		);
	}

	uint64_t TheTreacheryOfWhales::ExecutePart2(std::vector<int> crabPositions)
	{
		int average = std::round(std::accumulate(crabPositions.begin(), crabPositions.end(), 0.0) / static_cast<int>(crabPositions.size()));

		// Calculate a few values around the average to find the minimum:
		uint64_t	minimumFuel = UINT64_MAX;

		for (int d = -3; d <= 3; ++d)
		{
			int alignPos = average + d;
			uint64_t fuelSpent = std::accumulate(crabPositions.begin(), crabPositions.end(), 0ull,
				[alignPos](uint64_t fuelSpent, int position)
				{
					int distance = std::abs(alignPos - position);
					return fuelSpent + (distance * (distance + 1) / 2);
				}
			);

			minimumFuel = std::min(fuelSpent, minimumFuel);
		}

		return minimumFuel;
	}
}
