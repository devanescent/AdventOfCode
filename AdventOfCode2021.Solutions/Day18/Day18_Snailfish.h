#pragma once
#include "DayT.h"
#include "SnailfishNumberProcessor.h"

namespace AdventOfCode::Year2021::Day18
{
	class Snailfish : public DayT<std::unique_ptr<SnailfishNum>, SnailfishNumberProcessor>
	{
	public:
		Snailfish();

	protected:
		uint64_t ExecutePart1(std::vector<std::unique_ptr<SnailfishNum>> snailfishNums) override;
	};
}