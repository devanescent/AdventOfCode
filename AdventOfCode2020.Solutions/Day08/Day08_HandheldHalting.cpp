#include "Day08_HandheldHalting.h"
#include "ExecutionContext.h"

namespace AdventOfCode::Year2020::Day08
{
	Day08::HandheldHalting::HandheldHalting() : DayT(8, "Handheld Halting")	{}

	uint64_t Day08::HandheldHalting::ExecutePart1(std::vector<Instruction> instructions)
	{
		ExecutionContext ctx;
		int instrIndex = 0;

		// Execute until one instruction is executed a second time - meaning a cycle has been detected
		while (!ctx.HasBeenExecuted(instrIndex))
		{
			instrIndex = instructions[instrIndex].Execute(ctx);
		}

		return ctx.GetAccumulator();
	}

	uint64_t Day08::HandheldHalting::ExecutePart2(std::vector<Instruction> instructions)
	{
		// Try swapping JMP / NOP instructions until the program terminates:
		auto jmpOrNop = std::find_if(instructions.begin(), instructions.end(),
			[](const Instruction& instr) { return instr.IsJMPorNOP(); });

		while (jmpOrNop != instructions.end())
		{
			jmpOrNop->SwapJMPandNOP();

			ExecutionContext ctx;
			int instrIndex = 0;
			while (!ctx.HasBeenExecuted(instrIndex))
			{
				if (instrIndex < instructions.size())
					instrIndex = instructions[instrIndex].Execute(ctx);
				else
					return ctx.GetAccumulator();
			}

			// Swap back and try next instruction:
			jmpOrNop->SwapJMPandNOP();
			jmpOrNop = std::find_if(jmpOrNop + 1, instructions.end(),
				[](const Instruction& instr) { return instr.IsJMPorNOP(); });
		}

		return 0ull;
	}
}
