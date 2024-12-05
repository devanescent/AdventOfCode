#pragma once
#include "InputProcessorWithContext.h"

namespace AdventOfCode::Year2024::Day05
{
	using PageOrderingRules = std::vector<std::pair<int, int>>;
	using PageUpdate = std::vector<int>;

	class PrintingRulesProcessor : public InputProcessorWithContextBase<PageUpdate, PageOrderingRules>
	{
	public:
		std::pair<std::vector<PageUpdate>, PageOrderingRules> Process(std::vector<std::string> input) override;
	};
}
