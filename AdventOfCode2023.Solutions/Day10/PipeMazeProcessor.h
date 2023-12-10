#pragma once
#include "InputProcessorWithContext.h"
#include "Pipe.h"

namespace AdventOfCode::Year2023::Day10
{
	class PipeMazeProcessor : public InputProcessorWithContextBase<Pipe, Point<int>>
	{
	public:
		std::pair<std::vector<Pipe>, Point<int>> Process(std::vector<std::string> input) override;
	};
}
