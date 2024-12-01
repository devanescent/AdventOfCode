#include "LocationsListProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2024::Day01
{
	std::vector<LocationList> LocationsListProcessor::Process(std::vector<std::string> input)
	{
		// Initialize two lists:
		std::vector<LocationList> locationLists{ {}, {} };

		for (const auto& line : input)
		{
			std::istringstream iss(line);
			int num1, num2;

			iss >> num1 >> num2;
			locationLists[0].push_back(num1);
			locationLists[1].push_back(num2);
		}

		return locationLists;
	}
}
