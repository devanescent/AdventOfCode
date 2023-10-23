#pragma once
#include "DayT.h"
#include "SoundInstructionsProcessor.h"

namespace AdventOfCode::Year2017::Day18
{
	// ---------------------------------------------------------------------------
	// Day18: Duet
	// ---------------------------------------------------------------------------
	class Duet : public DayT<SoundInstructionsProcessor>
	{
	public:
		Duet();

	protected:
		uint64_t ExecutePart1(std::vector<SoundInstruction> input) override;
		uint64_t ExecutePart2(std::vector<SoundInstruction> input) override;
	};
}
