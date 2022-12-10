#pragma once
#include "DayT.h"
#include "InstructionProcessor.h"

namespace AdventOfCode::Year2022::Day10
{
	// ---------------------------------------------------------------------------
	// Day10: Cathode-Ray Tube
	// ---------------------------------------------------------------------------
	class CathodeRayTube : public DayT<InstructionProcessor>
	{
	public:
		CathodeRayTube();

	protected:
		uint64_t ExecutePart1(std::vector<Instruction> instructions) override;
		uint64_t ExecutePart2(std::vector<Instruction> instructions) override;
	};
}
