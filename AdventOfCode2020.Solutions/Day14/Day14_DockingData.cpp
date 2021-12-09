#include "Day14_DockingData.h"

namespace AdventOfCode::Year2020::Day14
{
	DockingData::DockingData() : DayTC(14, "Docking Data") {}

	uint64_t DockingData::ExecutePart1(std::vector<InitializationInstruction> instrs, InitializationContext instrCtx)
	{
		for (auto& instr : instrs)
			instr.Execute(instrCtx);

		return instrCtx.GetMemorySum();
	}
}




