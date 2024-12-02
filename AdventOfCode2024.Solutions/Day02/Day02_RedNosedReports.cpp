#include "Day02_RedNosedReports.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2024::Day02
{
	RedNosedReports::RedNosedReports() : DayT(2, "Red-Nosed Reports") { }

	bool IsSafeIncreasing(int diff) { return diff >= 1 && diff <= 3; }
	bool IsSafeDecreasing(int diff) { return diff <= -1 && diff >= -3; }

	bool IsReportSafe(const Report& report)
	{
		// Calculate differences between levels:
		std::vector<int> diffs;
		std::adjacent_difference(report.begin(), report.end(), std::back_inserter(diffs));

		// Ignore first element which is copied by adjacent_difference:
		return std::all_of(diffs.begin() + 1, diffs.end(), IsSafeIncreasing) ||
			   std::all_of(diffs.begin() + 1, diffs.end(), IsSafeDecreasing);
	}

	uint64_t RedNosedReports::ExecutePart1(std::vector<Report> reports)
	{
		return std::ranges::count_if(reports, IsReportSafe);
	}

	uint64_t RedNosedReports::ExecutePart2(std::vector<Report> reports)
	{
		uint64_t safeReports = 0;

		std::vector<int> diffs;
		for (const Report& report : reports)
		{
			if (IsReportSafe(report))
				++safeReports;
			else
			{
				// If report wasn't safe, try removing a single level from it and test again:
				for (auto i = 0; i < report.size(); ++i)
				{
					// Make a copy and remove level:
					auto dampenedReport = report;
					dampenedReport.erase(dampenedReport.begin() + i);

					if (IsReportSafe(dampenedReport))
					{
						++safeReports;
						break;
					}
				}
			}
		}

		return safeReports;
	}
}
