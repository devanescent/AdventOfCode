#pragma once
#include "DayTC.h"
#include "CartAndTracksProcessor.h"

namespace AdventOfCode::Year2018::Day13
{
	// ---------------------------------------------------------------------------
	// Day 13: Mine Cart Madness
	// ---------------------------------------------------------------------------
	class MineCartMadness : public DayTC<CartsAndTracksProcessor, std::string>
	{
	public:
		MineCartMadness();

	protected:
		virtual std::string ExecutePart1(std::vector<Minecart> mineCarts, MineTracks tracks) override;
		virtual std::string ExecutePart2(std::vector<Minecart> mineCarts, MineTracks tracks) override;
	};
}