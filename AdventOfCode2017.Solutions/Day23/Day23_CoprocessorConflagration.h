#pragma once
#include "DayT.h"
#include "InstructionsProcessor.h"

namespace AdventOfCode::Year2017::Day23
{
	// ---------------------------------------------------------------------------
	// Day23: Coprocessor Conflagration
	// ---------------------------------------------------------------------------
	class CoprocessorConflagration : public DayT<InstructionsProcessor>
	{
	public:
		CoprocessorConflagration();

	protected:
		uint64_t ExecutePart1(std::vector<Instruction> instructions) override;
		uint64_t ExecutePart2(std::vector<Instruction> instructions) override;
	};
}
