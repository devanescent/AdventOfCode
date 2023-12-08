#include "NetworkProcessor.h"
#include <algorithm>
#include <regex>

namespace AdventOfCode::Year2023::Day08
{
	std::pair<std::vector<NetworkNode>, std::vector<Direction>> NetworkProcessor::Process(std::vector<std::string> input)
	{
		std::pair<std::vector<NetworkNode>, std::vector<Direction>> network;
		std::vector<NetworkNode>& nodes = network.first;
		std::vector<Direction>& directions = network.second;

		// First line: directions
		std::transform(input[0].begin(), input[0].end(), std::back_inserter(directions),
			[](char c) { return c == 'L' ? Direction::Left : Direction::Right; });

		// Skip empty line, rest of the lines are nodes:
		std::regex nodePattern("([A-Z0-9]{3}) = \\(([A-Z0-9]{3})\\, ([A-Z0-9]{3})\\)");
		std::smatch matches;

		for (auto lineIt = input.begin() + 2; lineIt != input.end(); ++lineIt)
		{
			std::regex_search(*lineIt, matches, nodePattern);
			nodes.emplace_back(matches[1].str(), matches[2].str(), matches[3].str());
		}

		return network;
	}
}
