#include "InstructionProcessor.h"

namespace AdventOfCode::Year2020::Day08
{
	std::vector<Instruction> InstructionProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Instruction> instructions;

		for (const std::string instrLine : input)
		{
			std::string instr = instrLine.substr(0, 3);
			if (_stricmp(instr.c_str(), "acc") == 0)
				instructions.push_back(Instruction(Instruction::InstrType::ACC, atoi(instrLine.c_str() + 4)));
			else if (_stricmp(instr.c_str(), "jmp") == 0)
				instructions.push_back(Instruction(Instruction::InstrType::JMP, atoi(instrLine.c_str() + 4)));
			else if (_stricmp(instr.c_str(), "nop") == 0)
				instructions.push_back(Instruction(Instruction::InstrType::NOP, 0));
		}

		return instructions;
	}

}