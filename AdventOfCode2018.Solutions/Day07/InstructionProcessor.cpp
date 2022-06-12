#include "InstructionProcessor.h"
#include <map>

namespace AdventOfCode::Year2018::Day07
{
	std::vector<InstructionStep> InstructionProcessor::Process(std::vector<std::string> input)
	{
		// Prepare al 26 steps:
		std::map<char, InstructionStep> steps;

		// Assign precoditions:
		for (const std::string& instr : input)
		{
			// Pre- / Post-Condition:
			char stepIds[] = { instr[5], instr[36] };

			// Insert both parts of the step:
			auto step = steps.find(stepIds[0]);
			if (step == steps.end())
				steps.insert(std::make_pair(stepIds[0], stepIds[0]));

			step = steps.find(stepIds[1]);
			if (step == steps.end())
				step = steps.insert(std::make_pair(stepIds[1], stepIds[1])).first;

			// Assign precondition:
			step->second.AddPrecondition(stepIds[0]);
		}

		// Extract values from map into vector:
		std::vector<InstructionStep> stepsAsVec;
		stepsAsVec.reserve(steps.size());
		std::transform(steps.begin(), steps.end(), std::back_inserter(stepsAsVec),
			[](const auto& s) { return s.second; }
		);
		return stepsAsVec;
	}
}
