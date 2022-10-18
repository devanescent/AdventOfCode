#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2020::Day10
{
	class AdapterArray : public DayT<IntProcessor<IntProcessingMode::ValuePerLine>>
	{
	public:
		AdapterArray();

	protected:
		uint64_t ExecutePart1(std::vector<int> input) override;
		uint64_t ExecutePart2(std::vector<int> input) override;
	};
}