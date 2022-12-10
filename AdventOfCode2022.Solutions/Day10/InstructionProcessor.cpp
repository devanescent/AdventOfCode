#include "InstructionProcessor.h"

namespace AdventOfCode::Year2022::Day10
{
	std::vector<Instruction> InstructionProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Instruction> instructions;
		instructions.reserve(input.size());

		for (const std::string& line : input)
		{
			if (line == "noop")
				instructions.emplace_back(Instruction{ InstructionType::noop });
			else
				instructions.emplace_back(Instruction{ InstructionType::addx, std::stoi(line.substr(5)) });
		}

		return instructions;
	}
}
