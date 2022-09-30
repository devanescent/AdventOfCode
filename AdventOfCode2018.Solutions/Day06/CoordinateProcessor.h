#pragma once
#include "InputProcessorWithContext.h"
#include "Coord.h"

namespace AdventOfCode::Year2018::Day06
{
	class CoordinateProcessor : public InputProcessorWithContextBase<Coord, BoundingBox>
	{
	public:
		std::pair<std::vector<Coord>, BoundingBox> Process(std::vector<std::string> input) override;
	};
}

