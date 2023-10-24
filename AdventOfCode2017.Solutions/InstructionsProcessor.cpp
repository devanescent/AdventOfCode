#include "InstructionsProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2017
{
	std::vector<Instruction> InstructionsProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Instruction> instructions;

		for (const std::string& line : input)
		{
			std::istringstream iss(line);
			std::string str;

			// Instruction type:
			iss >> str;
			InstructionType instrType;
			if (str == "snd")
				instrType = InstructionType::PlaySound;
			else if (str == "set")
				instrType = InstructionType::Set;
			else if (str == "add")
				instrType = InstructionType::Add;
			else if (str == "sub")
				instrType = InstructionType::Subtract;
			else if (str == "mul")
				instrType = InstructionType::Multiply;
			else if (str == "mod")
				instrType = InstructionType::Modulo;
			else if (str == "rcv")
				instrType = InstructionType::RecoverSound;
			else if (str == "jgz")
				instrType = InstructionType::JumpGreaterZero;
			else if (str == "jnz")
				instrType = InstructionType::JumpNotZero;

			InstructionParameter p1, p2;
			InstructionParameter* currentP = &p1;
			while (iss >> str)
			{
				if (str[0] >= 'a' && str[0] <= 'z')
				{
					currentP->ValType = ValueType::Register;
					currentP->Value = str[0];
				}
				else
				{
					currentP->ValType = ValueType::Literal;
					currentP->Value = std::stoll(str);
				}

				currentP = &p2;
			}

			instructions.emplace_back(instrType, p1, p2);
		}

		return instructions;
	}
}
