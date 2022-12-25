#pragma once
#include "DayT.h"
#include "SNAFUProcessor.h"

namespace AdventOfCode::Year2022::Day25
{
	// ---------------------------------------------------------------------------
	// Day25: Full of Hot Air
	// ---------------------------------------------------------------------------
	class FullOfHotAir : public DayT<SNAFUProcessor>
	{
	public:
		FullOfHotAir();

	protected:
		uint64_t ExecutePart1(std::vector<SNAFUNumber> numbers) override;
		uint64_t ExecutePart2(std::vector<SNAFUNumber> numbers) override;
	};
}
