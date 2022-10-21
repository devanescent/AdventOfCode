#pragma once
#include "InputProcessorWithContext.h"
#include "MessageRules.h"

namespace AdventOfCode::Year2020::Day19
{
	class MessageRuleProcessor : public InputProcessorWithContextBase<std::string, MessageRuleCollection>
	{
	public:
		std::pair<std::vector<std::string>, MessageRuleCollection> Process(std::vector<std::string> input) override;
	};
}


