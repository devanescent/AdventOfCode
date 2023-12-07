#include "Day07_CamelCards.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2023::Day07
{
	CamelCards::CamelCards() : DayT(7, "Camel Cards") { }

	uint64_t CamelCards::ExecutePart1(std::vector<PlayedCards> playedHands)
	{
		// Calculate all hand types before sorting:
		for (auto& playedHand : playedHands)
			playedHand.SetHandType();

		std::sort(playedHands.begin(), playedHands.end());

		uint64_t totalWinnings = 0;
		for (int rank = 1; rank <= playedHands.size(); ++rank)
		{
			totalWinnings += rank * playedHands[rank - 1].Bid;
		}

		return totalWinnings;
	}

	uint64_t CamelCards::ExecutePart2(std::vector<PlayedCards> playedHands)
	{
		// Calculate all hand types with jokers before sorting:
		for (auto& playedHand : playedHands)
		{
			playedHand.EnableJoker();
			playedHand.SetHandType();
		}

		std::sort(playedHands.begin(), playedHands.end());

		uint64_t totalWinnings = 0;
		for (int rank = 1; rank <= playedHands.size(); ++rank)
		{
			totalWinnings += rank * playedHands[rank - 1].Bid;
		}

		return totalWinnings;
	}
}
