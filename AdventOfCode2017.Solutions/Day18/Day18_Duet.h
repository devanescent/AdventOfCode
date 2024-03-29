﻿#pragma once
#include "DayT.h"
#include "InstructionsProcessor.h"

namespace AdventOfCode::Year2017::Day18
{
	// ---------------------------------------------------------------------------
	// Day18: Duet
	// ---------------------------------------------------------------------------
	class Duet : public DayT<InstructionsProcessor>
	{
	public:
		Duet();

	protected:
		uint64_t ExecutePart1(std::vector<Instruction> instructions) override;
		uint64_t ExecutePart2(std::vector<Instruction> instructions) override;
	};
}
