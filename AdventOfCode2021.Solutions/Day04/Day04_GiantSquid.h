#pragma once
#include "DayTC.h"
#include "BingoBoardProcessor.h"

namespace AdventOfCode::Year2021::Day04
{
	class GiantSquid : public DayTC<BingoBoard, std::vector<int>, BingoProcessor>
	{
	public:
		GiantSquid();

	protected:
		uint64_t ExecutePart1(std::vector<BingoBoard> boards, std::vector<int> drawnNumbers) override;
	};
}