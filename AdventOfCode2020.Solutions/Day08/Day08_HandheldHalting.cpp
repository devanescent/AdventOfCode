#include "Day08_HandheldHalting.h"
#include "ExecutionContext.h"

namespace AdventOfCode::Year2020::Day08
{
	Day08::HandheldHalting::HandheldHalting() : DayT(8, "Handheld Halting")	{}

	uint64_t Day08::HandheldHalting::ExecutePart1(std::vector<Instruction> instructions)
	{
		if (instructions.empty())
			return 0;

		ExecutionContext ctx;
		// Execute until one instruction is executed a second time - meaning a cycle has been detected
		auto stackPtr = instructions.begin();
		while (stackPtr->Execute(stackPtr, ctx));

		return ctx.Accumulator;
	}
}
