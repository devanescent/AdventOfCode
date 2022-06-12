#pragma once
#include "DayT.h"
#include "RectangleClaimProcessor.h"

namespace AdventOfCode::Year2018::Day03
{
	// ---------------------------------------------------------------------------
	// Day01: ReportRepair 
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