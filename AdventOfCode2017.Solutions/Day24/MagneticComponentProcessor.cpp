#include "MagneticComponentProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2017::Day24
{
	std::vector<MagneticComponent> MagneticComponentProcessor::Process(std::vector<std::string> input)
	{
		std::vector<MagneticComponent> components;

		for (int i = 0; i < input.size(); ++i)
		{
			std::istringstream iss(input[i]);

			MagneticComponent comp;
			comp.ID = (i + 1);

			char comma;
			iss >> comp.Port1 >> comma >> comp.Port2;

			components.emplace_back(comp);
		}

		return components;
	}
}
