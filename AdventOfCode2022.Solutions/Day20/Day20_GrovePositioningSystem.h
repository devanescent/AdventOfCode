#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2022::Day20
{
	// ---------------------------------------------------------------------------
	// Day20: Grove Positioning System
	// ---------------------------------------------------------------------------
	class GrovePositioningSystem : public DayT<IntProcessor<IntProcessingMode::ValuePerLine>>
	{
	public:
		GrovePositioningSystem();

	protected:
		uint64_t ExecutePart1(std::vector<int> nums) override;
		uint64_t ExecutePart2(std::vector<int> nums) override;
	};
}
