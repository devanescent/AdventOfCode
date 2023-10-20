#include "HexGridProcessor.h"
#include <algorithm>
#include <sstream>

namespace AdventOfCode::Year2017::Day11
{
	std::vector<HexDirection> HexGridProcessor::Process(std::vector<std::string> input)
	{
		std::vector<HexDirection> directions;
		directions.reserve(input.size());

		std::istringstream iss = std::istringstream(input[0]);
		std::string dirStr;

		while (std::getline(iss, dirStr, ','))
		{
			if (dirStr == "n")
				directions.push_back(HexDirection::North);
			else if (dirStr == "ne")
				directions.push_back(HexDirection::NorthEast);
			else if (dirStr == "nw")
				directions.push_back(HexDirection::NorthWest);
			else if (dirStr == "s")
				directions.push_back(HexDirection::South);
			else if (dirStr == "se")
				directions.push_back(HexDirection::SouthEast);
			else if (dirStr == "sw")
				directions.push_back(HexDirection::SouthWest);
		}

		return directions;
	}
}
