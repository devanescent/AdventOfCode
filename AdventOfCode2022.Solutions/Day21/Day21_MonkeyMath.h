#pragma once
#include "DayT.h"
#include "MonkeyMathProcessor.h"

namespace AdventOfCode::Year2022::Day21
{
	// ---------------------------------------------------------------------------
	// Day21: Monkey Math
	// ---------------------------------------------------------------------------
	class MonkeyMath : public DayT<MonkeyMathProcessor>
	{
	public:
		MonkeyMath();

	protected:
		uint64_t ExecutePart1(std::map<std::string, YellingMonkey> monkeys) override;
		uint64_t ExecutePart2(std::map<std::string, YellingMonkey> monkeys) override;
	};
}
