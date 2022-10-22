#pragma once
#include "DayT.h"
#include "Deck.h"
#include "DeckProcessor.h"

namespace AdventOfCode::Year2020::Day22
{
	class CrabCombat : public DayT<DeckProcessor>
	{
	public:
		CrabCombat();

	protected:
		uint64_t ExecutePart1(std::vector<Deck> input) override;
		uint64_t ExecutePart2(std::vector<Deck> input) override;

	private:
		// Play the game according to the rules, returns 1 or 2 for the winner
		int PlayCombat(Deck& d1, Deck& d2);
		int PlayRecursiveCombat(Deck& d1, Deck& d2);
	};
}