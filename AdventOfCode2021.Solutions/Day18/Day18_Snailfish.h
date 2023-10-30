#pragma once
#include "DayT.h"
#include "SnailfishNumberProcessor.h"

namespace AdventOfCode::Year2021::Day18
{
	class Snailfish : public DayT<SnailfishNumberProcessor, uint64_t, uint64_t, true>
	{
	public:
		Snailfish();

	protected:
		uint64_t ExecutePart1(std::vector<std::unique_ptr<SnailfishNum>> snailfishNums) override;
		uint64_t ExecutePart2WithOrigData(const std::vector<std::string> input) override;

	private:
		std::unique_ptr<SnailfishNum> AddSnailfishNums(std::unique_ptr<SnailfishNum> num1, std::unique_ptr<SnailfishNum> num2);
	};
}