#pragma once
#include "DayT.h"
#include "RopeMovementProcessor.h"

namespace AdventOfCode::Year2022::Day09
{
	// ---------------------------------------------------------------------------
	// Day09: Rope Bridge
	// ---------------------------------------------------------------------------
	class RopeBridge : public DayT<RopeMovementProcessor>
	{
	public:
		RopeBridge();

	protected:
		uint64_t ExecutePart1(std::vector<RopeMovement> movements) override;
		uint64_t ExecutePart2(std::vector<RopeMovement> movements) override;
	};
}
