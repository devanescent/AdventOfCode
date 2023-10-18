#pragma once
#include "DayT.h"
#include "RegisterInstructionProcessor.h"

namespace AdventOfCode::Year2017::Day08
{
	// ---------------------------------------------------------------------------
	// Day08: I Heard You Like Registers
	// ---------------------------------------------------------------------------
	class IHeardYouLikeRegisters : public DayT<RegisterInstructionProcessor>
	{
	public:
		IHeardYouLikeRegisters();

	protected:
		uint64_t ExecutePart1(std::vector<RegisterInstruction> instructions) override;
		uint64_t ExecutePart2(std::vector<RegisterInstruction> instructions) override;
	};
}
