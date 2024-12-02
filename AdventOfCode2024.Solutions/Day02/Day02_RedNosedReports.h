#pragma once
#include "DayT.h"
#include "ReportsProcessor.h"

namespace AdventOfCode::Year2024::Day02
{
	// ---------------------------------------------------------------------------
	// Day02: Red-Nosed Reports
	// ---------------------------------------------------------------------------
	class RedNosedReports : public DayT<ReportsProcessor>
	{
	public:
		RedNosedReports();

	protected:
		uint64_t ExecutePart1(std::vector<Report> reports) override;
		uint64_t ExecutePart2(std::vector<Report> reports) override;
	};
}
