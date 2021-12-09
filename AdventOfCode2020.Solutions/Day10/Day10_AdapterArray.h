#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2020::Day10
{
	class AdapterArray : public DayT<int, IntProcessor<IntProcessingMode::ValuePerLine>>
	{
	public:
		AdapterArray();

	protected:
		uint64_t ExecutePart1(std::vector<int> input) override;
	};
}