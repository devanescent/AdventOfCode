#include "ScratchcardProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2023::Day04
{
	std::vector<Scratchcard> ScratchcardProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Scratchcard> scratchcards;

		for (const auto& line : input)
		{
			std::istringstream iss(line);

			Scratchcard sc;
			std::string s;

			// Ignore card name + number
			iss >> s >> s;

			// First set of numbers (up until '|'):
			while (iss >> s && s != "|")
				sc.WinningNumbers.insert(std::stoi(s));

			// Second set of numbers:
			while (iss >> s)
				sc.Numbers.insert(std::stoi(s));

			scratchcards.emplace_back(sc);
		}

		return scratchcards;
	}
}
