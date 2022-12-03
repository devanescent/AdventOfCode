#pragma once
#include "DayT.h"
#include "RucksackProcessor.h"

namespace AdventOfCode::Year2022::Day03
{
	// ---------------------------------------------------------------------------
	// Day03: Rucksack Reorganization
	// ---------------------------------------------------------------------------
	class RucksackReorganization : public DayT<RucksackProcessor>
	{
	public:
		RucksackReorganization();

	protected:
		uint64_t ExecutePart1(std::vector<Rucksack> rucksacks) override;
		uint64_t ExecutePart2(std::vector<Rucksack> rucksacks) override;
	};
}
