#pragma once
#include "DayTC.h"
#include "OrigamiProcessor.h"

namespace AdventOfCode::Year2021::Day13
{
	class TransparentOrigami : public DayTC<OrigamiProcessor>
	{
	public:
		TransparentOrigami();

	protected:
		uint64_t ExecutePart1(std::vector<FoldInstruction> foldInstrs, OrigamiPaper paper) override;
		uint64_t ExecutePart2(std::vector<FoldInstruction> foldInstrs, OrigamiPaper paper) override;

	private:
		void FoldPaper(OrigamiPaper& paper, const FoldInstruction& foldInstr);
		void PrintResult(OrigamiPaper& foldedPaper);
	};
}