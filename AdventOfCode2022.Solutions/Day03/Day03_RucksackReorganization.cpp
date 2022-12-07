#include "Day03_RucksackReorganization.h"
#include <numeric>

namespace AdventOfCode::Year2022::Day03
{
	RucksackReorganization::RucksackReorganization() : DayT(3, "Rucksack Reorganization") { }

	int GetItemPrio(Rucksack::Item item)
	{
		return (item >= 'a' && item <= 'z')
			? item - 'a' + 1	// Prio: 1 - 26
			: item - 'A' + 27;	// Prio: 27 - 52
	}

	uint64_t RucksackReorganization::ExecutePart1(std::vector<Rucksack> rucksacks)
	{
		return std::accumulate(rucksacks.begin(), rucksacks.end(), 0ull,
			[](uint64_t prioSum, const Rucksack& r)
			{
				Rucksack::Item item = r.GetDuplicateItem();
				return prioSum + GetItemPrio(item);
			}
		);
	}

	uint64_t RucksackReorganization::ExecutePart2(std::vector<Rucksack> rucksacks)
	{
		uint64_t prioSum = 0;

		// Process rucksacks in groups of three:
		for (int i = 0; i < rucksacks.size(); i += 3)
		{
			Rucksack::Item badge = rucksacks[i].GetBadge(rucksacks[i+1], rucksacks[i+2]);
			prioSum += GetItemPrio(badge);
		}

		return prioSum;
	}
}
