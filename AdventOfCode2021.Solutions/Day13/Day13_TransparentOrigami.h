#pragma once
#include "DayTC.h"
#include "OrigamiProcessor.h"

namespace AdventOfCode::Year2021::Day13
{
	class TransparentOrigami : public DayTC<FoldInstruction, OrigamiPaper, OrigamiProcessor>
	{
	public:
		TransparentOrigami();

	protected:
		uint64_t ExecutePart1(std::vector<FoldInstruction> foldInstrs, OrigamiPaper paper) override;
	};
}