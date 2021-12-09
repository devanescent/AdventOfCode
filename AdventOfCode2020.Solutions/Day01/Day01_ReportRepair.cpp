#include "Day01_ReportRepair.h"
#include "Utils.h"

namespace AdventOfCode::Year2020::Day01
{
	ReportRepair::ReportRepair(int targetSum) : DayT(1, "Report Repair"), 
		m_targetSum(targetSum)
	{}

	uint64_t Day01::ReportRepair::ExecutePart1(std::vector<int> report)
	{
		if (!report.empty())
		{
			if (auto res = FindPairForGivenSum(report, m_targetSum))
				return static_cast<uint64_t>(*res.value().first) * (*res.value().second);
		}

		return 0;
	}
}
