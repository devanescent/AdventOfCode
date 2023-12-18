#include "DigPlanProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2023::Day18
{
	std::vector<DigPlan> DigPlanProcessor::Process(std::vector<std::string> input)
	{
		std::vector<DigPlan> digPlans;

		for (const auto& line : input)
		{
			std::istringstream iss(line);
			DigPlan digPlan;

			// Direction:
			char dir;
			iss >> dir;
			switch (dir)
			{
				case 'U': digPlan.dy = -1; break;
				case 'D': digPlan.dy = +1; break;
				case 'L': digPlan.dx = -1; break;
				case 'R': digPlan.dx = +1; break;
			}

			// Steps:
			iss >> digPlan.Steps;

			// Color:
			iss >> digPlan.Color;
			digPlan.Color = digPlan.Color.substr(2, digPlan.Color.length() - 3); // trim '(#' and ')'

			digPlans.emplace_back(digPlan);
		}

		return digPlans;
	}
}
