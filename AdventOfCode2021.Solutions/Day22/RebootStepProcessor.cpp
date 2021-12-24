#include "RebootStepProcessor.h"
#include <sstream>
#include <algorithm>

namespace AdventOfCode::Year2021::Day22
{
	std::vector<RebootStep> RebootStepProcessor::Process(std::vector<std::string> input)
	{
		std::vector<RebootStep> steps;
		steps.reserve(input.size());

		for (auto& step : input)
		{
			// Replace ',' and '=' with spaces so the input string can be processed with stringstream:
			std::replace(step.begin(), step.end(), ',', ' ');
			std::replace(step.begin(), step.end(), '=', ' ');

			std::istringstream iss(step);
			int fromX, toX, fromY, toY, fromZ, toZ;
			char state[4], coord, dot;	// state = 'on'|'off', coord = 'x'|'y'|'z', dot='.'

			iss >> state 
				>> coord >> fromX >> dot >> dot >> toX
				>> coord >> fromY >> dot >> dot >> toY
				>> coord >> fromZ >> dot >> dot >> toZ;

			steps.emplace_back(RebootStep{ state[1] == 'n', fromX, toX, fromY, toY, fromZ, toZ });
		}
		
		return steps;
	}
}