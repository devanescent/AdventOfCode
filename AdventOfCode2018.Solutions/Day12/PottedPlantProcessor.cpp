#include "PottedPlantProcessor.h"
#include <algorithm>
#include <iterator>

namespace AdventOfCode::Year2018::Day12
{
	std::pair<PotRow, PlantRules> PottedPlantProcessor::Process(std::vector<std::string> input)
	{
		// Initial set of plants:
		std::string initialState = input[0].substr(input[0].find(':') + 2);

		// List of rules for spreading of plants
		PlantRules rules;
		for (auto rule = input.begin() + 2; rule != input.end(); ++rule)
			rules.try_emplace(rule->substr(0, 5), rule->back() == '#');

		return std::make_pair(initialState, rules);
	}
}
