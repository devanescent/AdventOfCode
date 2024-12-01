#include "Day01_HistorianHysteria.h"
#include <algorithm>
#include <map>
#include <numeric>

namespace AdventOfCode::Year2024::Day01
{
	HistorianHysteria::HistorianHysteria() : DayT(1, "Historian Hysteria") { }

	uint64_t HistorianHysteria::ExecutePart1(std::vector<LocationList> locationLists)
	{
		auto& list1 = locationLists[0];
		auto& list2 = locationLists[1];

		// Compare elements in lists by size, so sort first:
		std::ranges::sort(list1);
		std::ranges::sort(list2);;

		// Sum up distances:
		uint64_t totalDistance = 0;
		for (int i = 0; i < list1.size(); ++i)
		{
			totalDistance += std::abs(list1[i] - list2[i]);
		}

		return totalDistance;
	}

	uint64_t HistorianHysteria::ExecutePart2(std::vector<LocationList> locationLists)
	{
		auto& list1 = locationLists[0];
		auto& list2 = locationLists[1];

		// Count occurrences of numbers in the second list:
		std::map<int, int> numCounts;
		for (int n : list2)
			++numCounts[n];

		// Calculate similarity score by multiplying each number with how often it appered in the second list:
		uint64_t similarityScore = 0;
		for (int i = 0; i < list1.size(); ++i)
		{
			auto cntIt = numCounts.find(list1[i]);
			if (cntIt != numCounts.end())
			{
				similarityScore += list1[i] * cntIt->second;
			}
		}

		return similarityScore;
	}
}
