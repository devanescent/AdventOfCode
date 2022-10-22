#include "DeckProcessor.h"
#include <algorithm>
#include <deque>

namespace AdventOfCode::Year2020::Day22
{
	std::vector<Deck> DeckProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Deck> decks;

		// empty line separating the two decks:
		auto delimiter = std::find(input.begin(), input.end(), "");

		if (input.size() > 3 && delimiter != input.end())
		{
			std::deque<int> firstDeck, secondDeck;
			// skip first line for first deck (= label 'Player 1:')
			std::transform(++input.begin(), delimiter, std::back_inserter(firstDeck), [](const std::string& str) { return atoi(str.c_str()); });
			decks.emplace_back(Deck(firstDeck));

			// skip delimiter and the line immediatly following after that (= label 'Player 2:'):
			std::transform(++++delimiter, input.end(), std::back_inserter(secondDeck), [](const std::string& str) { return atoi(str.c_str()); });
			decks.emplace_back(Deck(secondDeck));
		}

		return decks;
	}
}

