#pragma once
#include "DayT.h"
#include "GroveProcessor.h"

namespace AdventOfCode::Year2022::Day23
{
	// ---------------------------------------------------------------------------
	// Day23: Unstable Diffusion
	// ---------------------------------------------------------------------------
	class UnstableDiffusion : public DayT<GroveProcessor>
	{
	public:
		UnstableDiffusion();

	protected:
		uint64_t ExecutePart1(std::vector<Elf> elves) override;
		uint64_t ExecutePart2(std::vector<Elf> elves) override;
	};
}
