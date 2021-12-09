#pragma once
#include "InputProcessorWithContext.h"
#include "BingoBoard.h"

namespace AdventOfCode::Year2021::Day04
{
	class BingoProcessor : public InputProcessorWithContextBase<BingoBoard, std::vector<int>>
	{
	public:
		std::pair<std::vector<BingoBoard>, std::vector<int>> Process(std::vector<std::string> input) override;
	};
}