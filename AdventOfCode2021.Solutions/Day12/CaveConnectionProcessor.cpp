#include "CaveConnectionProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2021::Day12
{
	std::vector<CaveConnection> CaveConnectionProcessor::Process(std::vector<std::string> input)
	{
		std::vector<CaveConnection> connections;
		connections.reserve(input.size());

		for (const std::string line : input)
		{
			std::istringstream iss(line);
			std::string cave1, cave2;

			std::getline(iss, cave1, '-');
			std::getline(iss, cave2, '-');

			connections.emplace_back(cave1, cave2);
		}

		return connections;
	}

}