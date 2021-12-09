#pragma once
#include "DayT.h"
#include "Instruction.h"
#include "InstructionProcessor.h"

namespace AdventOfCode::Year2020::Day08
{
	class HandheldHalting : public DayT<Instruction, InstructionProcessor>
	{
	public:
		HandheldHalting();

	protected:
		uint64_t ExecutePart1(std::vector<Instruction> instructions) override;
	};
}