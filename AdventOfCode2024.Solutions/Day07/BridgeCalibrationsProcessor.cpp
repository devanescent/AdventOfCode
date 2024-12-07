#include "BridgeCalibrationsProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2024::Day07
{
	std::vector<Calibration> BridgeCalibrationsProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Calibration> calibrations;

		for (const auto& line : input)
		{
			std::istringstream iss(line);
			
			Calibration c;
			char colon;

			iss >> c.TestValue >> colon;
			c.EquationValues = std::vector<int>(std::istream_iterator<int>(iss), std::istream_iterator<int>());
			calibrations.emplace_back(c);
		}

		return calibrations;
	}
}
