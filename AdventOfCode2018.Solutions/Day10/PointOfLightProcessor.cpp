#include "PointOfLightProcessor.h"
#include <regex>

namespace AdventOfCode::Year2018::Day10
{
	std::vector<PointOfLight> PointOfLightProcessor::Process(std::vector<std::string> input)
	{
		std::vector<PointOfLight> points;
		points.reserve(input.size());

		std::regex policyPattern = std::regex("position=< *([\\-0-9]+), *([\\-0-9]+)> velocity=< *([\\-0-9]+), *([\\-0-9]+)>");
		std::smatch matches;

		for (const std::string& line : input)
		{
			// Number of matches == 5: the whole string plus all 4 capture groups
			if (std::regex_search(line, matches, policyPattern) && matches.size() == 5)
			{
				int x = atoi(matches[1].str().c_str());
				int y = atoi(matches[2].str().c_str());
				int dx = atoi(matches[3].str().c_str());
				int dy = atoi(matches[4].str().c_str());

				points.emplace_back(x, y, dx, dy);
			}
		}

		return points;
	}
}
