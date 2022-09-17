#include "ComputationSampleProcessor.h"

namespace AdventOfCode::Year2018::Day16
{
	std::vector<ComputationSample> ComputationSampleProcessor::Process(std::vector<std::string> input)
	{
		std::vector<ComputationSample> samples;

		for (int l = 0; l < input.size(); l += 4)
		{
			// Separation between computation samples and the test program are multiple empty lines
			if (input[l].empty() && input[l + 1].empty())
				break;
			else if (input[l].empty())
				continue; // Skip single empty lines

			Register regBefore(input[l].substr(9));
			Register regAfter(input[l + 2].substr(9));
			Instruction instr(input[l + 1]);

			samples.emplace_back(regBefore, regAfter, instr);
		}

		return samples;
	}
}
