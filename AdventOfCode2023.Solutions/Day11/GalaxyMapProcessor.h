#pragma once
#include "InputProcessorWithContext.h"
#include "Point.h"
#include "SpaceExpansions.h"

namespace AdventOfCode::Year2023::Day11
{
	class GalaxyMapProcessor : public InputProcessorWithContextBase<Point<uint64_t>, SpaceExpansions>
	{
	public:
		std::pair<std::vector<Point<uint64_t>>, SpaceExpansions> Process(std::vector<std::string> input) override;
	};
}
