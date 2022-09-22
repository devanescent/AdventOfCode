#include "ComputationSampleProcessor.h"

namespace AdventOfCode::Year2018::Day16
{
	std::pair<std::vector<ComputationSample>, std::vector<Instruction>> ComputationSampleProcessor::Process(std::vector<std::string> input)
	{
		std::pair<std::vector<ComputationSample>, std::vector<Instruction>> result;
		
		int currentLineIx = 0;

		// First half: samples for matching numbers to opcodes
		for (currentLineIx; currentLineIx < input.size(); currentLineIx += 4)
		{
			// Separation between computation samples and the test program are multiple empty lines
			if (input[currentLineIx].empty())
				break;

			// Instruction format: all numbers separated by spaces
			int opCode, A, B, C;
			std::istringstream iss(input[currentLineIx + 1]);
			iss >> opCode >> A >> B >> C;

			result.first.emplace_back(
				input[currentLineIx].substr(9),     // register before
				input[currentLineIx + 2].substr(9), // register after
				Instruction(opCode, A, B, C) // Instruction - this may result in the wrong opcode, which will be corrected later
			);
		}

		// Second half: the program to be executed
		for (currentLineIx; currentLineIx < input.size(); ++currentLineIx)
		{
			// Each non-empty line is an instruction
			if (!input[currentLineIx].empty())
			{
				int opCode, A, B, C;
				std::istringstream iss(input[currentLineIx]);
				iss >> opCode >> A >> B >> C;

				result.second.emplace_back(Instruction(opCode, A, B, C));
			}
		}

		return result;
	}
}
