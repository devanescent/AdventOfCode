#pragma once
#include "InputProcessor.h"
#include "EnhancementRule.h"

namespace AdventOfCode::Year2017::Day21
{
	class EnhancementRulesProcessor : public InputProcessorBase<EnhancementRule>
	{
	public:
		std::vector<EnhancementRule> Process(std::vector<std::string> input) override;
	};
}
