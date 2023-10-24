#include "Day23_CoprocessorConflagration.h"

namespace AdventOfCode::Year2017::Day23
{
	CoprocessorConflagration::CoprocessorConflagration() : DayT(23, "Coprocessor Conflagration") { }

	uint64_t CoprocessorConflagration::ExecutePart1(std::vector<Instruction> instructions)
	{
		std::map<char, int64_t> registers;
		auto currentInstr = instructions.begin();

		// Count MUL instructions:
		uint64_t mulCnt = 0;
		while (currentInstr != instructions.end())
		{
			if (currentInstr->Type == InstructionType::Multiply)
				++mulCnt;

			currentInstr->ExecuteCommon(currentInstr, registers);
		}

		return mulCnt;
	}

	uint64_t CoprocessorConflagration::ExecutePart2(std::vector<Instruction> instructions)
	{
		return 0ull;
	}
}
