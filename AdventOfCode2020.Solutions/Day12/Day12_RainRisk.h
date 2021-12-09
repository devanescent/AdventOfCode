#pragma once
#include "DayT.h"
#include "NavInstruction.h"
#include "NavInstructionProcessor.h"

namespace AdventOfCode::Year2020::Day12
{
	class RainRisk : public DayT<NavInstruction, NavInstructionProcessor>
	{
	public:
		RainRisk(NavDirection startingDirection);

	protected:
		uint64_t ExecutePart1(std::vector<NavInstruction> navInstrs) override;
	};
}

