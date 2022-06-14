#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2018::Day08
{
	// ---------------------------------------------------------------------------
	// Day08: MemoryManeuver 
	// ---------------------------------------------------------------------------
	class MemoryManeuver : public DayT<IntProcessor<IntProcessingMode::ValuesAsSpaceSeparatedLine>>
	{
	public:
		MemoryManeuver();
		uint64_t ExecutePart1(std::vector<int> rootNodeData) override;
	};
}