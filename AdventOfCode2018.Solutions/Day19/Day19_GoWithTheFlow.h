#pragma once
#include "DayTC.h"
#include "InstructionProcessor.h"

namespace AdventOfCode::Year2018::Day19
{
	// ---------------------------------------------------------------------------
	// Day19: Go With The Flow
	// ---------------------------------------------------------------------------
	class GoWithTheFlow : public DayTC<InstructionProcessor>
	{
	public:
		GoWithTheFlow();

		uint64_t ExecutePart1(std::vector<Instruction> program, int instrPtrReg) override;
	};
}