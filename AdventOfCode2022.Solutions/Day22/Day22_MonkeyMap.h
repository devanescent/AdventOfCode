#pragma once
#include "DayTC.h"
#include "MonkeyMapProcessor.h"

namespace AdventOfCode::Year2022::Day22
{
	// ---------------------------------------------------------------------------
	// Day22: Monkey Map
	// ---------------------------------------------------------------------------
	class MonkeyMap : public DayTC<MonkeyMapProcessor>
	{
	public:
		MonkeyMap();

	protected:
		uint64_t ExecutePart1(std::vector<MoveInstruction> moves, JungleMap map) override;
		uint64_t ExecutePart2(std::vector<MoveInstruction> moves, JungleMap map) override;
	};
}
