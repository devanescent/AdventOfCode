#pragma once
#include "DayT.h"
#include "MonkeyProcessor.h"

namespace AdventOfCode::Year2022::Day11
{
	// ---------------------------------------------------------------------------
	// Day11: Monkey in the Middle
	// ---------------------------------------------------------------------------
	class MonkeyInTheMiddle : public DayT<MonkeyProcessor>
	{
	public:
		MonkeyInTheMiddle();

	protected:
		uint64_t ExecutePart1(std::vector<Monkey> monkeys) override;
		uint64_t ExecutePart2(std::vector<Monkey> monkeys) override;
	};
}
