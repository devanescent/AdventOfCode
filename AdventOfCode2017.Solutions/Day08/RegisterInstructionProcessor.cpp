#include "RegisterInstructionProcessor.h"
#include <algorithm>
#include <sstream>

namespace AdventOfCode::Year2017::Day08
{
	std::vector<RegisterInstruction> RegisterInstructionProcessor::Process(std::vector<std::string> input)
	{
		std::vector<RegisterInstruction> regInstrs;
		regInstrs.reserve(input.size());

		std::transform(input.begin(), input.end(), std::back_inserter(regInstrs),
			[](const std::string& line)
			{
				// [reg_name] [inc|dec] [val] if [comp_reg] [comp_op] [comp_val]
				std::istringstream iss(line);

				RegisterInstruction regInstr;

				// Name:
				iss >> regInstr.Name;

				// Modification:
				std::string modStr;
				iss >> modStr;
				regInstr.Modification = modStr == "inc"
					? RegisterModification::Increase
					: RegisterModification::Decrease;

				iss >> regInstr.Value;

				// Condition:
				iss >> regInstr.CompRegName >> regInstr.CompRegName // discard "if" first
					 >> regInstr.ComRegOp
					 >> regInstr.CompRegValue;

				return regInstr;
			});

		return regInstrs;
	}
}
