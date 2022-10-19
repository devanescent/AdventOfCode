#pragma once
#include "DayT.h"
#include "InitializationProcessor.h"

namespace AdventOfCode::Year2020::Day14
{
	class DockingData : public DayT<InitializationProcessor>
	{
	public:
		DockingData();

	protected:
		uint64_t ExecutePart1(std::vector<InitializationInstruction> instrs) override;
		uint64_t ExecutePart2(std::vector<InitializationInstruction> instrs) override;
	};
}


