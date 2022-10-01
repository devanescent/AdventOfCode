#include "Day01_ReportRepair.h"
#include "Utils.h"

namespace AdventOfCode::Year2020::Day01
{
	ReportRepair::ReportRepair() : DayT(1, "Report Repair") {}

	uint64_t Day01::ReportRepair::ExecutePart1(std::vector<int> report)
	{
		if (!report.empty())
		{
			if (auto res = FindPairForGivenSum(report, 2020))
				return static_cast<uint64_t>(*res.value().first) * (*res.value().second);
		}

		return 0;
	}

	uint64_t Day01::ReportRepair::ExecutePart2(std::vector<int> report)
	{
		while (!report.empty())
		{
			int third = report.back();
			report.pop_back();

			if (auto res = FindPairForGivenSum(report, 2020 - third))
				return static_cast<uint64_t>(*res.value().first) * (*res.value().second) * third;
		}
	}
}
