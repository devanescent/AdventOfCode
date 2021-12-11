#include "Day01_SonarSweep.h"
#include <numeric>
#include <functional>

namespace AdventOfCode::Year2021::Day01
{
	SonarSweep::SonarSweep() : DayT(1, "Sonar Sweep") {}

	// ---------------------------------------------------------------------------
	// Part 1:
	// ---------------------------------------------------------------------------
	uint64_t SonarSweep::ExecutePart1(std::vector<int> report)
	{
		// Check for each element if it is greater than the previous:
		std::adjacent_difference(report.begin(), report.end(), report.begin(), std::greater<>{});
		
		// Count where condition above is true (=1):
		return static_cast<uint64_t>(std::count(std::next(report.begin()), report.end(), 1));
	}

	// ---------------------------------------------------------------------------
	// Part 2:
	// ---------------------------------------------------------------------------
	uint64_t SonarSweep::ExecutePart2(std::vector<int> report)
	{
		uint64_t counts = 0;

		// Need at least 4 elements to do one comparison
		if (report.size() >= 4)
		{
			for (auto it1 = report.begin(), it2 = std::next(it1), it3 = std::next(it2), it4 = std::next(it3);
				it4 != report.end();
				++it1, ++it2, ++it3, ++it4
				)
			{
				if ((*it1 + *it2 + *it3) < (*it2 + *it3 + *it4)) ++counts;
			}
		}

		return counts;
	}
}

