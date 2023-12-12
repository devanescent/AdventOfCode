#include "Day12_HotSprings.h"
#include <numeric>

namespace AdventOfCode::Year2023::Day12
{
	HotSprings::HotSprings() : DayT(12, "Hot Springs") { }

	uint64_t HotSprings::ExecutePart1(std::vector<SpringReport> springReports)
	{
		return std::accumulate(springReports.begin(), springReports.end(), 0ull,
			[](uint64_t arrangementCount, auto& report)
			{
				return arrangementCount + report.CountArrangements();
			});
	}

	uint64_t HotSprings::ExecutePart2(std::vector<SpringReport> springReports)
	{
		return std::accumulate(springReports.begin(), springReports.end(), 0ull,
			[](uint64_t arrangementCount, auto& report)
			{
				auto origConditions = report.Conditions;
				auto origGroups = report.DamageGroups;

				// Append 4 copies:
				for (int i = 0; i < 4; ++i)
				{
					report.Conditions += "?" + origConditions;
					report.DamageGroups.insert(report.DamageGroups.end(), origGroups.begin(), origGroups.end());
				}

				return arrangementCount + report.CountArrangements();
			});
	}
}
