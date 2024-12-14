#include "RobotProcessor.h"
#include <regex>

namespace AdventOfCode::Year2024::Day14
{
	std::vector<Robot> RobotProcessor::Process(std::vector<std::string> input)
	{
		std::regex robotPattern(R"(p\=(\d+)\,(\d+) v\=(\-?\d+)\,(\-?\d+))");
		std::smatch matches;

		std::vector<Robot> robots;

		for (const std::string& line : input)
		{
			Robot r;

			std::regex_search(line, matches, robotPattern);
			r.Position.X = std::stoi(matches[1].str());
			r.Position.Y = std::stoi(matches[2].str());
			r.Velocity.X = std::stoi(matches[3].str());
			r.Velocity.Y = std::stoi(matches[4].str());

			robots.emplace_back(r);
		}

		return robots;
	}
}
