#include "Day22_CrabCombat.h"

namespace AdventOfCode::Year2020::Day22
{
	Day22::CrabCombat::CrabCombat() : DayT(22, "Crab Combat") {}

	uint64_t Day22::CrabCombat::ExecutePart1(std::vector<Deck> input)
	{
		uint64_t score = 0;

		if (input.size() >= 2)
		{
			Deck& d1 = input[0];
			Deck& d2 = input[1];

			int winner = PlayCombat(d1, d2);

			if (winner == 1)
				score = d1.GetScore();
			else if (winner == 2)
				score = d2.GetScore();
		}

		return score;
	}

	uint64_t CrabCombat::ExecutePart2(std::vector<Deck> input)
	{
		uint64_t score = 0;

		if (input.size() >= 2)
		{
			Deck& d1 = input[0];
			Deck& d2 = input[1];

			int winner = PlayRecursiveCombat(d1, d2);

			if (winner == 1)
				score = d1.GetScore();
			else if (winner == 2)
				score = d2.GetScore();
		}

		return score;
	}

	int CrabCombat::PlayCombat(Deck& d1, Deck& d2)
	{
		int winner = 0;

		// Game continues, until one deck is empty:
		while (d1.GetCardCount() != 0 && d2.GetCardCount() != 0)
		{
			// Plays a round: remove the first card from each deck and
			// add them to the winner's deck in correct order:
			auto card1 = d1.DrawCard();
			auto card2 = d2.DrawCard();

			if (card1 > card2)
			{
				d1.AddCardToBack(card1);
				d1.AddCardToBack(card2);
				winner = 1;
			}
			else
			{
				d2.AddCardToBack(card2);
				d2.AddCardToBack(card1);
				winner = 2;
			}
		}

		return winner;
	}

	int CrabCombat::PlayRecursiveCombat(Deck& d1, Deck& d2)
	{
		int winner = 0;

		std::vector<std::pair<Deck, Deck>> prevRounds; // to secure against infinite recursion

		// Game continues, until one deck is empty:
		while (d1.GetCardCount() != 0 && d2.GetCardCount() != 0)
		{
			// Before drawing a card, check if this round already happened before, in which case player 1 wins:
			if (std::find_if(prevRounds.begin(), prevRounds.end(),
				[&](const auto& prevRound) { return prevRound.first == d1 && prevRound.second == d2; }) != prevRounds.end())
			{
				return 1;
			}

			// Rmember this round:
			prevRounds.emplace_back(d1, d2);

			// Plays a round: remove the first card from each deck and
			// add them to the winner's deck in correct order:
			auto card1 = d1.DrawCard();
			auto card2 = d2.DrawCard();

			// Check if recursive combat is possible:
			if (d1.GetCardCount() >= card1 && d2.GetCardCount() >= card2)
			{
				// Create deck copies and start recursive round:
				Deck d1Copy = d1.CopyDeck(card1);
				Deck d2Copy = d2.CopyDeck(card2);

				winner = PlayRecursiveCombat(d1Copy, d2Copy);
			}
			else if (card1 > card2) // Play the round normally as before:
				winner = 1;
			else
				winner = 2;

			// Add cards to winner's deck:
			if (winner == 1)
			{
				d1.AddCardToBack(card1);
				d1.AddCardToBack(card2);
			}
			else // if (winner == 2)
			{
				d2.AddCardToBack(card2);
				d2.AddCardToBack(card1);
			}
		}

		return winner;
	}
}