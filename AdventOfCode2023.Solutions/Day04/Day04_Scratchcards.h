#pragma once
#include "DayT.h"
#include "ScratchcardProcessor.h"

namespace AdventOfCode::Year2023::Day04
{
	// ---------------------------------------------------------------------------
	// Day04: Scratchcards
	// ---------------------------------------------------------------------------
	class Scratchcards : public DayT<ScratchcardProcessor>
	{
	public:
		Scratchcards();

	protected:
		uint64_t ExecutePart1(std::vector<Scratchcard> scratchcards) override;
		uint64_t ExecutePart2(std::vector<Scratchcard> scratchcards) override;
	};
}
