#pragma once
#include "DayT.h"
#include "BlizzardProcessor.h"

namespace AdventOfCode::Year2022::Day24
{
	// ---------------------------------------------------------------------------
	// Day24: Blizzard Basin
	// ---------------------------------------------------------------------------
	class BlizzardBasin : public DayT<BlizzardProcessor>
	{
	public:
		BlizzardBasin();

	protected:
		uint64_t ExecutePart1(std::vector<Blizzard> blizzards) override;
		uint64_t ExecutePart2(std::vector<Blizzard> blizzards) override;
	};
}
