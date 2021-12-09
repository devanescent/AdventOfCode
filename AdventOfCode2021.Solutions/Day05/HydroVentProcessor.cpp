#include "HydroVentProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2021::Day05
{
	std::vector<HydroVentLine> HydroVentProcessor::Process(std::vector<std::string> input)
	{
		std::vector<HydroVentLine> hydroVents;
		hydroVents.reserve(input.size());

		for (std::string& line : input)
		{
			std::istringstream iss(line);
			
			// parsing components of the input string:
			int x1, y1, x2, y2;
			char comma;
			std::string arrow;

			// Format: "x1,y1 -> x2,y2"
			iss >> x1 >> comma >> y1 >> arrow >> x2 >> comma >> y2;
			hydroVents.push_back({ { x1, y1 }, { x2, y2 } });
		}

		return hydroVents;
	}
}