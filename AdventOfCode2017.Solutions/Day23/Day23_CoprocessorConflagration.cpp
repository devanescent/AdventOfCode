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
		// Manually optimized program from the input file:

		uint64_t h = 0;

		int64_t b = 108'400;
		const int64_t c = 125'400;

		while (b <= c)
		{
			for (int64_t d = 2; d < b; ++d)
			{
				if (b % d == 0)
				{
					++h;
					break;
				}
			}

			b += 17;
		}

		return h;
	}
}
