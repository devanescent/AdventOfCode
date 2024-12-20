#include "Day11_PlutonianPebbles.h"
#include <map>

namespace AdventOfCode::Year2024::Day11
{
	PlutonianPebbles::PlutonianPebbles() : DayT(11, "Plutonian Pebbles") { }

	uint64_t Blink(std::vector<int>& stones, int blinks)
	{
		// Calculate stones after the given number of blinks.
		// Because the position of each individual stone does not affect its transformation,
		// only keep track of how many stones of each value there are.
		std::map<uint64_t, uint64_t> stoneCounts;
		for (auto stone : stones)
		{
			++stoneCounts[stone];
		}

		// Process each blink:
		for (int i = 0; i < blinks; ++i)
		{
			// New stone counts:
			std::map<uint64_t, uint64_t> nextStoneCounts;

			for (const auto& [stone, count] : stoneCounts)
			{
				// All stones equal to 0 become 1:
				if (stone == 0)
					nextStoneCounts[1] += count;
				else
				{
					// All stones with an even string length will be split:
					auto stoneStr = std::to_string(stone);
					if (stoneStr.length() % 2 == 0)
					{
						auto split1 = stoneStr.substr(0, stoneStr.length() / 2);
						auto split2 = stoneStr.substr(stoneStr.length() / 2);

						nextStoneCounts[std::stoull(split1)] += count;
						nextStoneCounts[std::stoull(split2)] += count;
					}
					else
						// Otherwise, multiply with 2024:
						nextStoneCounts[stone * 2024] += count;
				}
			}

			// Replace current stone counts with the next:
			stoneCounts = std::move(nextStoneCounts);
		}

		// Sum up all stone counts:
		uint64_t totalStoneCount = 0;
		for (const auto& [stone, count] : stoneCounts)
			totalStoneCount += count;

		return totalStoneCount;
	}

	uint64_t PlutonianPebbles::ExecutePart1(std::vector<int> stones)
	{
		return Blink(stones, 25);
	}

	uint64_t PlutonianPebbles::ExecutePart2(std::vector<int> stones)
	{
		return Blink(stones, 75);
	}
}
