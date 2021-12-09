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
}

