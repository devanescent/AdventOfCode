#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2021::Day06
{
	class Lanternfish : public DayT<IntProcessor<IntProcessingMode::ValuesAsSingleLine>>
	{
	public:
		Lanternfish();

	protected:
		uint64_t ExecutePart1(std::vector<int> fish) override;
		uint64_t ExecutePart2(std::vector<int> fish) override;
	};
}