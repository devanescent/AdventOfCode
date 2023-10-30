#pragma once
#include "DayT.h"
#include "SNAFUProcessor.h"

namespace AdventOfCode::Year2022::Day25
{
	// ---------------------------------------------------------------------------
	// Day25: Full of Hot Air
	// ---------------------------------------------------------------------------
	class FullOfHotAir : public DayT<SNAFUProcessor, std::string>
	{
	public:
		FullOfHotAir();

	protected:
		std::string ExecutePart1(std::vector<SNAFUNumber> numbers) override;
	};
}
