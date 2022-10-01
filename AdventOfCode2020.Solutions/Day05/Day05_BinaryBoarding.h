#pragma once
#include "DayT.h"
#include "BoardingPassProcessor.h"

namespace AdventOfCode::Year2020::Day05
{
	class BinaryBoarding : public DayT< BoardingPassProcessor>
	{
	public:
		BinaryBoarding();

		uint64_t ExecutePart1(std::vector<int> seatIDs) override;
		uint64_t ExecutePart2(std::vector<int> seatIDs) override;
	};
}