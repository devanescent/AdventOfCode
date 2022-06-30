#include "PottedPlantProcessor.h"
#include <algorithm>
#include <iterator>

namespace AdventOfCode::Year2018::Day12
{
	std::pair<std::deque<PottedPlant>, std::map<std::string, bool>> PottedPlantProcessor::Process(std::vector<std::string> input)
	{
		std::string initialState = input[0].substr(input[0].find(':') + 2);
		std::deque<PottedPlant> pots;

		// Initial set of plants:
		for (char pot : initialState)
			pots.emplace_back(pots.empty() ? 0 : pots.back().PotIndex() + 1, pot == '#');

		// List of rules for spreading of plants
		std::map<std::string, bool> rules;
		for (auto rule = input.begin() + 2; rule != input.end(); ++rule)
			rules[rule->substr(0, 5)] = rule->back() == '#';

		return std::make_pair(pots, rules);
	}
}
