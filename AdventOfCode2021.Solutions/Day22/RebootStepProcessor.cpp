#include "RebootStepProcessor.h"
#include <sstream>
#include <algorithm>

namespace AdventOfCode::Year2021::Day22
{
	std::vector<RebootStep> RebootStepProcessor::Process(std::vector<std::string> input)
	{
		std::vector<RebootStep> steps;
		steps.reserve(input.size());

		for (auto& line : input)
		{
			// Replace ',' and '=' with spaces so the input string can be processed with stringstream:
			std::replace(line.begin(), line.end(), ',', ' ');
			std::replace(line.begin(), line.end(), '=', ' ');

			std::istringstream iss(line);
			RebootStep step;
			std::string state;	// state = 'on'|'off', 
			char coord, dot;	// coord = 'x'|'y'|'z', dot = '.'

			iss >> state 
				>> coord >> step.Region.XRange.Start >> dot >> dot >> step.Region.XRange.End
				>> coord >> step.Region.YRange.Start >> dot >> dot >> step.Region.YRange.End
				>> coord >> step.Region.ZRange.Start >> dot >> dot >> step.Region.ZRange.End;

			if (state == "on")
				step.NewState = RebootState::on;
			else
				step.NewState = RebootState::off;

			steps.emplace_back(step);
		}
		
		return steps;
	}
}