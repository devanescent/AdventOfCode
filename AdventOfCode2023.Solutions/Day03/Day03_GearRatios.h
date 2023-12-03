#pragma once
#include "DayT.h"
#include "EngineSchematicsProcessor.h"

namespace AdventOfCode::Year2023::Day03
{
	// ---------------------------------------------------------------------------
	// Day03: Gear Ratios
	// ---------------------------------------------------------------------------
	class GearRatios : public DayT<EngineSchematicsProcessor>
	{
	public:
		GearRatios();

	protected:
		uint64_t ExecutePart1(std::vector<PartNumber> partNumbers) override;
		uint64_t ExecutePart2(std::vector<PartNumber> partNumbers) override;
	};
}
