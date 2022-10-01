#pragma once
#include "DayTC.h"
#include "..\Day19\InstructionProcessor.h"

namespace AdventOfCode::Year2018::Day21
{
	// Reuse Instruction / InstructionProcessor class from Day 16 / 19:
	using Instruction = AdventOfCode::Year2018::Day16::Instruction;
	using InstructionProcessor = AdventOfCode::Year2018::Day19::InstructionProcessor;

	// ---------------------------------------------------------------------------
	// Day21: Chronal Conversion
	// ---------------------------------------------------------------------------
	class ChronalConversion : public DayTC<InstructionProcessor>
	{
	public:
		ChronalConversion();

		uint64_t ExecutePart1(std::vector<Instruction> program, int instrPtrReg) override;
		uint64_t ExecutePart2(std::vector<Instruction> program, int instrPtrReg) override;
	};
}