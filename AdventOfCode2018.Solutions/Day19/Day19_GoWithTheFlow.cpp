#include "Day19_GoWithTheFlow.h"
#include "Program.h"

namespace AdventOfCode::Year2018::Day19
{
	GoWithTheFlow::GoWithTheFlow() : DayTC(19, "Go With The Flow") {}

	uint64_t GoWithTheFlow::ExecutePart1(std::vector<Instruction> program, int instrPtrReg)
	{
		Program prog(program);
		Register<6> reg;

		prog.Execute(instrPtrReg, reg);
		return reg[0];
	}
}