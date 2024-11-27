#include "AluInstructionProcessor.h"
#include <map>
#include <sstream>

namespace AdventOfCode::Year2021::Day24
{
	const std::map<std::string, InstructionType, std::less<>> typemap
	{
		{ "inp", InstructionType::Input },
		{ "add", InstructionType::Add },
		{ "mul", InstructionType::Multiply },
		{ "div", InstructionType::Divide },
		{ "mod", InstructionType::Modulo },
		{ "eql", InstructionType::Equal }
	};

	std::vector<AluInstruction> AluInstructionProcessor::Process(std::vector<std::string> input)
	{
		std::vector<AluInstruction> instructions;

		std::string op, arg1, arg2;
		for (const auto& line : input)
		{
			std::istringstream iss(line);
			iss >> op >> arg1 >> arg2;
			instructions.emplace_back(typemap.at(op), arg1, arg2);
		}

		return instructions;
	}
}
