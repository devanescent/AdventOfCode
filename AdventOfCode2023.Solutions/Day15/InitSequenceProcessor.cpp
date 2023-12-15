#include "InitSequenceProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2023::Day15
{
	std::vector<std::string> InitSequenceProcessor::Process(std::vector<std::string> input)
	{
		std::vector<std::string> initSteps;

		std::istringstream iss(input[0]);
		std::string initStep;
		while (std::getline(iss, initStep, ','))
		{
			initSteps.emplace_back(initStep);
		}
		
		return initSteps;
	}
}
