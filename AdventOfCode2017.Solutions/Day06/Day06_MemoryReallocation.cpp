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
			++redistrCount;
			
			// Remember configuration:
			prevConfigurations.insert(memoryBanks);

			RedistributeBlocks(memoryBanks);

		} while (!prevConfigurations.contains(memoryBanks));

		return redistrCount;
	}

	uint64_t MemoryReallocation::ExecutePart2(std::vector<int> memoryBanks)
	{
		std::vector<std::vector<int>> prevConfigurations;
		auto duplicateConfig = prevConfigurations.end();

		uint64_t redistrCount = 0ull;
		do
		{
			++redistrCount;
			
			// Remember configuration:
			prevConfigurations.push_back(memoryBanks);

			RedistributeBlocks(memoryBanks);

			duplicateConfig = std::find(prevConfigurations.begin(), prevConfigurations.end(), memoryBanks);

		} while (duplicateConfig == prevConfigurations.end());

		return std::distance(duplicateConfig, prevConfigurations.end());
	}

	void MemoryReallocation::RedistributeBlocks(std::vector<int>& memoryBanks)
	{
		auto bankToRedistr = std::max_element(memoryBanks.begin(), memoryBanks.end());

		int blocksToRedistr = *bankToRedistr;
		*bankToRedistr = 0;

		// Amount added to all banks:
		for (auto& bank : memoryBanks)
		{
			bank += blocksToRedistr / memoryBanks.size();
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
	}
}
