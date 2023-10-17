#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2017::Day06
{
	// ---------------------------------------------------------------------------
	// Day06: Memory Reallocation
	// ---------------------------------------------------------------------------
	class MemoryReallocation : public DayT<IntProcessor<IntProcessingMode::ValuesAsSpaceSeparatedLine>>
	{
	public:
		MemoryReallocation();

		uint64_t ExecutePart1(std::vector<int> memoryBanks) override;
		uint64_t ExecutePart2(std::vector<int> memoryBanks) override;

	private:
		void RedistributeBlocks(std::vector<int>& memoryBanks);
	};
}
