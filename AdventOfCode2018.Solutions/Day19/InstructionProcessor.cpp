#include "InstructionProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2018::Day19
{
	using OpCode = AdventOfCode::Year2018::Day16::OpCode;

	std::pair<std::vector<Instruction>, int> InstructionProcessor::Process(std::vector<std::string> input)
	{
		std::pair<std::vector<Instruction>, int> result;
		result.first.reserve(input.size());

		// First line: register for instruction pointer (0-5)
		result.second = input[0].back() - '0';

		// Rest of input: instructions
		for (auto line = ++input.begin(); line != input.end(); ++line)
		{
			std::istringstream iss(*line);

			// Format: opcode as text; registers as numbers, separated by spaces
			OpCode opCode;
			int A, B, C;

			iss >> opCode >> A >> B >> C;
			result.first.emplace_back(opCode, A, B, C);
		}

		return result;
	}
}
