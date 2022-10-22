#include "InstructionProcessor.h"

namespace AdventOfCode::Year2020::Day08
{
	std::vector<Instruction> InstructionProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Instruction> instructions;

		int instrIndex = 0;
		for (const std::string& instrLine : input)
		{
			if (instrLine.rfind("acc", 0) == 0)
				instructions.push_back(Instruction(instrIndex, Instruction::InstrType::ACC, atoi(instrLine.c_str() + 4)));
			else if (instrLine.rfind("jmp", 0) == 0)
				instructions.push_back(Instruction(instrIndex, Instruction::InstrType::JMP, atoi(instrLine.c_str() + 4)));
			else if (instrLine.rfind("nop", 0) == 0)
				instructions.push_back(Instruction(instrIndex, Instruction::InstrType::NOP, 0));

			++instrIndex;
		}

		return instructions;
	}

}