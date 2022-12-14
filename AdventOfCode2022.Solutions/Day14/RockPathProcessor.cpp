#include "RockPathProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2022::Day14
{
	std::vector<RockPath> RockPathProcessor::Process(std::vector<std::string> input)
	{
		std::vector<RockPath> rockPaths;

		for (const std::string& line : input)
		{
			std::istringstream iss(line);
			std::string pointStr;
		
			RockPath rockPath;

			do
			{
				iss >> pointStr;
				int x = std::stoi(pointStr);
				int y = std::stoi(pointStr.substr(pointStr.find(',') + 1));
				rockPath.Path.emplace_back(x, y);
			}
			while (iss >> pointStr); // skip the " -> " parts

			rockPaths.emplace_back(std::move(rockPath));
		}

		return rockPaths;
	}
}
