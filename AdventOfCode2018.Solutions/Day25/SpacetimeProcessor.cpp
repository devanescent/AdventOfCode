#include "SpacetimeProcessor.h"
#include <iostream>
#include <sstream>

namespace AdventOfCode::Year2018::Day25
{
	std::vector<SpacetimeFixpoint> SpacetimeProcessor::Process(std::vector<std::string> input)
	{
		std::vector<SpacetimeFixpoint> fixPoints;
		fixPoints.reserve(input.size());

		for (const std::string& line : input)
		{
			std::istringstream iss(line);
			std::string coord;

			std::getline(iss, coord, ',');
			int x = atoi(coord.c_str());

			std::getline(iss, coord, ',');
			int y = atoi(coord.c_str());

			std::getline(iss, coord, ',');
			int z = atoi(coord.c_str());

			std::getline(iss, coord, ',');
			int t = atoi(coord.c_str());

			fixPoints.emplace_back(x, y, z, t);
		}

		return fixPoints;
	}
}
