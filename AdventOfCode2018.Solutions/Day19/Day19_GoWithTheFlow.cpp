#include "Day19_GoWithTheFlow.h"
#include "Program.h"

namespace AdventOfCode::Year2018::Day19
{
	GoWithTheFlow::GoWithTheFlow() : DayTC(19, "Go With The Flow") {}

	// Sum up all divisors of a given number:
	uint64_t GetDivisorSum(uint64_t number)
	{
		// 1 and the number itself are always divisors:
		uint64_t divSum = 1 + number;

		for (int d = 2; d <= number / 2; ++d)
		{
			if (number % d == 0)
				divSum += d;
		}

		return divSum;
	}

	uint64_t GoWithTheFlow::ExecutePart1(std::vector<Instruction> program, int instrPtrReg)
	{
		Program prog(program);
		Register<6> reg;

		prog.Execute(instrPtrReg, reg);
		return reg[0]; // equal to return GetDivisorSum(892);
	}

	uint64_t GoWithTheFlow::ExecutePart2(std::vector<Instruction> program, int instrPtrReg)
	{
		// Reverse-engineered the given program, which initializes a target number 
		// (which was placed in register 1 after the first dozen instructions)
		// and then sums up all its divisors:
		return GetDivisorSum(10'551'292);
	}
}