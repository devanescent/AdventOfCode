#pragma once
#include "InputProcessorWithContext.h"
#include "TowelPatterns.h"

namespace AdventOfCode::Year2024::Day19
{
	class TowelPatternProcessor : public InputProcessorWithContextBase<DisplayDesign, TowelPatterns>
	{
	public:
		std::pair<std::vector<DisplayDesign>, TowelPatterns> Process(std::vector<std::string> input) override;
	};
}
