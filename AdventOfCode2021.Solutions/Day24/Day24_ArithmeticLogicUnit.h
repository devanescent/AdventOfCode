#pragma once
#include "DayT.h"
#include "AluInstructionProcessor.h"

namespace AdventOfCode::Year2021::Day24
{
	// ---------------------------------------------------------------------------
	// Day24: Arithmetic Logic Unit
	// ---------------------------------------------------------------------------
	class ArithmeticLogicUnit : public DayT<AluInstructionProcessor>
	{
	public:
		ArithmeticLogicUnit();

	protected:
		uint64_t ExecutePart1(std::vector<AluInstruction> instructions) override;
		uint64_t ExecutePart2(std::vector<AluInstruction> instructions) override;
	};
}
