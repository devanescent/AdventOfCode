#pragma once
#include "InputProcessorWithContext.h"
#include "GridMap.h"
#include "Point.h"

namespace AdventOfCode::Year2024::Day15
{
	class WarehouseProcessor : public InputProcessorWithContextBase<Point<int>, GridMap>
	{
	public:
		std::pair<std::vector<Point<int>>, GridMap> Process(std::vector<std::string> input) override;
	};
}
