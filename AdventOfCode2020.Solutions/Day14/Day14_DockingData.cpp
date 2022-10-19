#include "Day14_DockingData.h"

namespace AdventOfCode::Year2020::Day14
{
	DockingData::DockingData() : DayT(14, "Docking Data") {}

	uint64_t DockingData::ExecutePart1(std::vector<InitializationInstruction> instrs)
	{
		InitializationContext ctx;

		for (auto& instr : instrs)
			instr.Execute(ctx);

		return ctx.GetMemorySum();
	}

	uint64_t DockingData::ExecutePart2(std::vector<InitializationInstruction> instrs)
	{
		InitializationContextV2 ctx;

		for (auto& instr : instrs)
			instr.Execute(ctx);

		return ctx.GetMemorySum();
	}
}




