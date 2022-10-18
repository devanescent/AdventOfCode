#pragma once
#include "DayT.h"
#include "NavInstruction.h"
#include "NavInstructionProcessor.h"

namespace AdventOfCode::Year2020::Day12
{
	class RainRisk : public DayT<NavInstructionProcessor>
	{
	public:
		RainRisk();

	protected:
		uint64_t ExecutePart1(std::vector<NavInstruction> navInstrs) override;
		uint64_t ExecutePart2(std::vector<NavInstruction> navInstrs) override;
	};
}

