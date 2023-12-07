#include "CamelCardsProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2023::Day07
{
	std::vector<PlayedCards> CamelCardsProcessor::Process(std::vector<std::string> input)
	{
		std::vector<PlayedCards> playedHands;

		for (const auto& line : input)
		{
			std::istringstream iss(line);
			PlayedCards playedHand;

			iss >> playedHand.Hand >> playedHand.Bid;
			playedHands.emplace_back(playedHand);
		}

		return playedHands;
	}
}
