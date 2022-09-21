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


			// Instruction format: all numbers separated by spaces
			int opCode, A, B, C;
			std::istringstream iss(input[l + 1]);
			iss >> opCode >> A >> B >> C;

			samples.emplace_back(
				input[l].substr(9),     // register before
				input[l + 2].substr(9), // register after
				Instruction(static_cast<OpCode>(opCode), A, B, C) // Instruction - this may result in the wrong opcode, which will be corrected later
			);
		}

		return samples;
	}
}
