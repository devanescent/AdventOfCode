#pragma once
#include "DayTC.h"
#include "MessageRuleProcessor.h"

namespace AdventOfCode::Year2020::Day19
{
	class MonsterMessages : public DayTC<MessageRuleProcessor>
	{
	public:
		MonsterMessages();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> messages, MessageRuleCollection rules) override;
		uint64_t ExecutePart2(std::vector<std::string> messages, MessageRuleCollection rules) override;
	};
}
