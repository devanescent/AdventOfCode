#include "Day24_ArithmeticLogicUnit.h"
#include "ALU.h"

namespace AdventOfCode::Year2021::Day24
{
	ArithmeticLogicUnit::ArithmeticLogicUnit() : DayT(24, "Arithmetic Logic Unit") { }

	uint64_t ArithmeticLogicUnit::ExecutePart1(std::vector<AluInstruction> instructions)
	{
		// Analyzing the MONAD script results in the following conditions for the digits of the model number:
		//	d3 == d2 - 3
		//	d6 == d5 + 3
		//	d7 == d4 + 2
		//	d9 == d8 - 5
		//	d11 == d10 - 1
		//	d12 == d1 + 7
		//	d13 == d0 - 8

		std::string largestModelNumber = "92967699949891";

		// Verify the register z contains a 0 at the end of the program:
		ALU alu;
		for (const auto& instr : instructions)
			alu.ApplyInstruction(instr, largestModelNumber);

		if (alu.Z == 0)
			return std::stoull(largestModelNumber);
		else
			return 0;
	}

	uint64_t ArithmeticLogicUnit::ExecutePart2(std::vector<AluInstruction> instructions)
	{
		std::string smallestModelNumber = "91411143612181";

		// Verify the register z contains a 0 at the end of the program:
		ALU alu;
		for (const auto& instr : instructions)
			alu.ApplyInstruction(instr, smallestModelNumber);

		if (alu.Z == 0)
			return std::stoull(smallestModelNumber);
		else
			return 0;
	}
}
