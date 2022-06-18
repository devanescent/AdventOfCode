#pragma once
#include "DayTC.h"
#include "InitializationInstruction.h"
#include "InitializationProcessor.h"

namespace AdventOfCode::Year2020::Day14
{
	class DockingData : public DayTC<InitializationProcessor>
	{
	public:
		DockingData();

	protected:
		uint64_t ExecutePart1(std::vector<InitializationInstruction> instrs, InitializationContext instrCtx) override;
	};
}


