#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2021::Day15
{
	class Chiton : public DayT<IntArrayProcessor>
	{
	public:
		Chiton();

	protected:
		uint64_t ExecutePart1(std::vector<std::vector<int>> cave) override;
		uint64_t ExecutePart2(std::vector<std::vector<int>> cave) override;

	private:
		uint64_t FindLowestRiskPath(const std::vector<std::vector<int>>& cave);
	};
}