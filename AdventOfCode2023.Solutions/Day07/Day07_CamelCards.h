#pragma once
#include "DayT.h"
#include "CamelCardsProcessor.h"

namespace AdventOfCode::Year2023::Day07
{
	// ---------------------------------------------------------------------------
	// Day07: Camel Cards
	// ---------------------------------------------------------------------------
	class CamelCards : public DayT<CamelCardsProcessor>
	{
	public:
		CamelCards();

	protected:
		uint64_t ExecutePart1(std::vector<PlayedCards> playedHands) override;
		uint64_t ExecutePart2(std::vector<PlayedCards> playedHands) override;
	};
}
