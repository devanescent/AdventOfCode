#pragma once
#include "DayT.h"
#include "MirrorPatternProcessor.h"

namespace AdventOfCode::Year2023::Day13
{
	// ---------------------------------------------------------------------------
	// Day13: Point of Incidence
	// ---------------------------------------------------------------------------
	class PointOfIncidence : public DayT<MirrorPatternProcessor>
	{
	public:
		PointOfIncidence();

	protected:
		uint64_t ExecutePart1(std::vector<MirrorPattern> mirrorPatterns) override;
		uint64_t ExecutePart2(std::vector<MirrorPattern> mirrorPatterns) override;
	};
}
