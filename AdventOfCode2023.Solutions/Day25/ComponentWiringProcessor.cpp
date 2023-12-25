#include "ComponentWiringProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2023::Day25
{
	std::vector<Wiring> ComponentWiringProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Wiring> wirings;

		for (const auto& line : input)
		{
			std::istringstream iss(line);
			
			std::string compName;
			iss >> compName;
			compName.pop_back(); // remove ':'
			
			std::string conName;
			while (iss >> conName)
			{
				wirings.emplace_back(compName, conName);
			}
		}

		return wirings;
	}
}
