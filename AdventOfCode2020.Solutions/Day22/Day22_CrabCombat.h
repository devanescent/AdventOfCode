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

	private:
		int PlayRound(Deck& d1, Deck& d2);
	};
}