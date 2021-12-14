#include "PolymerProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2021::Day14
{
	std::pair<std::vector<PolymerRule>, std::string> PolymerProcessor::Process(std::vector<std::string> input)
	{
		std::vector<PolymerRule> polymerRules;
		for (int i = 2; i < input.size(); ++i)
		{
			const std::string& line = input[i];
			polymerRules.emplace_back(line[0], line[1], line.back());
		}

		return std::make_pair(polymerRules, input[0]);
	}
}