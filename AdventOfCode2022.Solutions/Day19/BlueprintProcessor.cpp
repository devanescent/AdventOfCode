#include "BlueprintProcessor.h"
#include <regex>

namespace AdventOfCode::Year2022::Day19
{
	std::vector<Blueprint> BlueprintProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Blueprint> blueprints;

		std::regex blueprintPattern(
			"Blueprint ([0-9]+): "
			"Each ore robot costs ([0-9]+) ore. "
			"Each clay robot costs ([0-9]+) ore. "
			"Each obsidian robot costs ([0-9]+) ore and ([0-9]+) clay. "
			"Each geode robot costs ([0-9]+) ore and ([0-9]+) obsidian."
		);

		std::smatch matches;
		for (const std::string& line : input)
		{
			std::regex_search(line, matches, blueprintPattern);
			blueprints.emplace_back(Blueprint
			{
				std::stoi(matches[1].str()),
				std::stoi(matches[2].str()),
				std::stoi(matches[3].str()),
				std::stoi(matches[4].str()),
				std::stoi(matches[5].str()),
				std::stoi(matches[6].str()),
				std::stoi(matches[7].str())
			});
		}

		return blueprints;
	}
}
