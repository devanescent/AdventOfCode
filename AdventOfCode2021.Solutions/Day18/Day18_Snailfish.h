#pragma once
#include "DayT.h"
#include "SnailfishNumberProcessor.h"

namespace AdventOfCode::Year2021::Day18
{
	class Snailfish : public DayT<SnailfishNumberProcessor>
	{
	public:
		Snailfish();
		uint64_t GetResultOnPart2(const std::vector<std::string> input) override;

	protected:
		uint64_t ExecutePart1(std::vector<std::unique_ptr<SnailfishNum>> snailfishNums) override;

	private:
		std::unique_ptr<SnailfishNum> AddSnailfishNums(std::unique_ptr<SnailfishNum> num1, std::unique_ptr<SnailfishNum> num2);
	};
}