#pragma once
#include "DayTC.h"
#include "CartAndTracksProcessor.h"

namespace AdventOfCode::Year2018::Day13
{
	// ---------------------------------------------------------------------------
	// Day 13: Mine Cart Madness
	// ---------------------------------------------------------------------------
	class MineCartMadness : public DayTC<CartsAndTracksProcessor>
	{
	public:
		MineCartMadness();

	protected:
		virtual uint64_t ExecutePart1(std::vector<Minecart> mineCarts, MineTracks tracks) override;
		virtual uint64_t ExecutePart2(std::vector<Minecart> mineCarts, MineTracks tracks) override;
	};
}