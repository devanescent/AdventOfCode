#include "Day19_GoWithTheFlow.h"

namespace AdventOfCode::Year2018::Day19
{
	template<int N>
	using Register = AdventOfCode::Year2018::Day16::Register<N>; // type-id is vector<T, Alloc<T>>

	GoWithTheFlow::GoWithTheFlow() : DayTC(19, "Go With The Flow") {}

	uint64_t GoWithTheFlow::ExecutePart1(std::vector<Instruction> program, int instrPtrReg)
	{
		int instrPtr = 0;
		Register<6> reg;

		while (instrPtr >= 0 && instrPtr < program.size())
		{
			// For each instruction:
			const Instruction& instr = program[instrPtr];

			// 1. The instruction pointer's value is written to the bound register just before the instruction is executed
			reg[instrPtrReg] = instrPtr;
			instr.ApplyToRegister(reg);

			// 2. After the instruction finishes, the bound value is written back to the instruction pointer
			instrPtr = reg[instrPtrReg];

			// 3. The instruction pointer's value is moved to the next instruction by adding 1
			++instrPtr;

			// The program halts, if the instruction pointer points outside of the program
		}

		return reg[0];
	}
}