#pragma once
#include "InputProcessorWithContext.h"
#include "FoldInstruction.h"

namespace AdventOfCode::Year2021::Day13
{
	using OrigamiPaper = std::vector<std::vector<bool>>;

	class OrigamiProcessor : public InputProcessorWithContextBase<FoldInstruction, OrigamiPaper>
	{
	public:
		std::pair<std::vector<FoldInstruction>, OrigamiPaper> Process(std::vector<std::string> input) override;
	};
}
