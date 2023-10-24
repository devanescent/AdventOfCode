#pragma once
#include "InputProcessorWithContext.h"
#include "Point.h"

namespace AdventOfCode::Year2017::Day22
{
	class GridComputingClusterProcessor : public InputProcessorWithContextBase<Point<int>, Point<int>>
	{
	public:
		std::pair<std::vector<Point<int>>, Point<int>> Process(std::vector<std::string> input) override;
	};
}
