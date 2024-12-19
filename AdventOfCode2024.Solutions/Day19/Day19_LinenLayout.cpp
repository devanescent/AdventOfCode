#include "Day19_LinenLayout.h"
#include <algorithm>

namespace AdventOfCode::Year2024::Day19
{
	LinenLayout::LinenLayout() : DayTC(19, "Linen Layout") { }

	uint64_t LinenLayout::ExecutePart1(std::vector<DisplayDesign> displayDesigns, TowelPatterns patterns)
	{
		// Count number of designs that can be made with available towel patterns:
		return std::count_if(displayDesigns.begin(), displayDesigns.end(),
			[&patterns](const DisplayDesign& displayDesign)
			{
				return patterns.CanCreateDesign(displayDesign, 0);
			});
	}

	uint64_t LinenLayout::ExecutePart2(std::vector<DisplayDesign> displayDesigns, TowelPatterns patterns)
	{
		// Count all possible options for creating the designs:
		uint64_t result = 0;
		for (const auto& displayDesign : displayDesigns)
		{
			std::string design;
			if (patterns.CanCreateDesign(displayDesign, 0))
			{
				result += patterns.CountDesignOptions(displayDesign, 0);
			}
		}

		return result;
	}
}
