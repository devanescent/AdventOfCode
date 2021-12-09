#include "Day22_CrabCombat.h"

namespace AdventOfCode::Year2020::Day22
{
	Day22::CrabCombat::CrabCombat() : DayT(22, "Crab Combat") {}

	uint64_t Day22::CrabCombat::ExecutePart1(std::vector<Deck> input)
	{
		uint64_t score = 0;

		if (input.size() >= 2)
		{
			Deck d1 = input[0];
			Deck d2 = input[1];

			int winner = 0;
			// Winner is determined, when one deck is empty:
			while (d1.ContainsCards() && d2.ContainsCards())
			{
				winner = PlayRound(d1, d2);
			}

			if (winner == 1)
				score = d1.GetScore();
			else if (winner == 2)
				score = d2.GetScore();
		}

		return score;
	}

	// Plays a round according to the rules and return the winner of this round:
	// '1' if the first deck won, '2' if the second deck won or '0' if it's a draw
	int Day22::CrabCombat::PlayRound(Deck & d1, Deck & d2)
	{
		auto card1 = d1.PopTop();
		auto card2 = d2.PopTop();

		if (card1 > card2)
		{
			d1.AddBack(card1);
			d1.AddBack(card2);
			return 1;
		}
		else if (card2 > card1)
		{
			d2.AddBack(card2);
			d2.AddBack(card1);
			return 2;
		}
		else
			return 0;
	}
}