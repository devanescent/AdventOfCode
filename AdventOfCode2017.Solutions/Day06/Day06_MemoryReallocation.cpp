#include "Day06_MemoryReallocation.h"
#include <algorithm>
#include <set>

namespace AdventOfCode::Year2017::Day06
{
	MemoryReallocation::MemoryReallocation() : DayT(6, "Memory Reallocation") { }

	uint64_t MemoryReallocation::ExecutePart1(std::vector<int> memoryBanks)
	{
		std::set<std::vector<int>> prevConfigurations;

		uint64_t redistrCount = 0ull;
		do
		{
			// Remember configuration:
			prevConfigurations.insert(memoryBanks);

			++redistrCount;
			auto bankToRedistr = std::max_element(memoryBanks.begin(), memoryBanks.end());

			int blocksToRedistr = *bankToRedistr;
			*bankToRedistr = 0;

			// Amount added to all banks:
			for (auto& bank : memoryBanks)
			{
				bank += blocksToRedistr / 4;
			}

			// Insert remaining blocks:
			int leftOverBlocks = blocksToRedistr % memoryBanks.size();
			auto bankIt = bankToRedistr + 1;
			for (int i = 0; i < leftOverBlocks; ++i)
			{
				if (bankIt == memoryBanks.end())
					bankIt = memoryBanks.begin();

				++(*bankIt);
				++bankIt;
			}
		} while (!prevConfigurations.contains(memoryBanks));

		return redistrCount;
	}

	uint64_t MemoryReallocation::ExecutePart2(std::vector<int> memoryBanks)
	{
		return uint64_t();
	}
}
