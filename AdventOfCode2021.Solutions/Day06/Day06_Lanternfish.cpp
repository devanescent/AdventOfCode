#include "Day06_Lanternfish.h"
#include <algorithm>
#include <numeric>
#include <map>

namespace AdventOfCode::Year2021::Day06
{
	Lanternfish::Lanternfish() : DayT(6, "Lanternfish") {}

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
	/// Executes part 1 of the day 06 challenge
	/// </summary>
	/// <param name="fish">- List of ages of the initial fish</param>
	/// <returns>Number of fishes after 80 days</returns>
	uint64_t Lanternfish::ExecutePart1(std::vector<int> fish)
	{
		for (int day = 0; day < 80; ++day)
		{			
			// Collect the new lanternfish to be added to the collection
			std::vector<int> newFish;

			std::for_each(fish.begin(), fish.end(),
				[&newFish](int& i)
				{
					if (i == 0)
					{
						newFish.push_back(8);
						i = 6;
					}
					else
						--i;
				}
			);

			// Make space and append new fish:
			fish.reserve(fish.size() + newFish.size());
			fish.insert(fish.end(), newFish.begin(), newFish.end());
		}
		
		 return fish.size();
	}

	/// <summary>
	/// Executes part 2 of the day 06 challenge
	/// </summary>
	/// <param name="fish">- List of ages of the initial fish</param>
	/// <returns>Number of fishes after 256 days</returns>
	uint64_t Lanternfish::ExecutePart2(std::vector<int> fish)
	{
		std::map<int, uint64_t> fishCounts;	// number of fish by age
		std::for_each(fish.begin(), fish.end(),
			[&fishCounts](int fish)
			{
				++fishCounts[fish];
			}
		);

		for (int day = 0; day < 256; ++day)
		{
			fishCounts = UpdateFishCounts(fishCounts);
		}

		return std::accumulate(fishCounts.begin(), fishCounts.end(), 0ull,
			[](uint64_t totalCount, const auto& entry)
			{
				return totalCount + entry.second;
			});
	}
}
