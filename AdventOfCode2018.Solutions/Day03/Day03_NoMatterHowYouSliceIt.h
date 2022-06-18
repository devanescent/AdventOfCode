#pragma once
#include "DayT.h"
#include "RectangleClaimProcessor.h"

namespace AdventOfCode::Year2018::Day03
{
	// ---------------------------------------------------------------------------
	// Day03: No Matter How You Slice It 
	// ---------------------------------------------------------------------------
	class NoMatterHowYouSliceIt : public DayT<RectangleClaimProcessor>
	{
	public:
		NoMatterHowYouSliceIt();

	protected:
		uint64_t ExecutePart1(std::vector<RectangleClaim> claims) override;
		uint64_t ExecutePart2(std::vector<RectangleClaim> claims) override;
	};
}