#pragma once
#include "DayT.h"
#include "SpringReportProcessor.h"

namespace AdventOfCode::Year2023::Day12
{
	// ---------------------------------------------------------------------------
	// Day12: Hot Springs
	// ---------------------------------------------------------------------------
	class HotSprings : public DayT<SpringReportProcessor>
	{
	public:
		HotSprings();

	protected:
		uint64_t ExecutePart1(std::vector<SpringReport> springReports) override;
		uint64_t ExecutePart2(std::vector<SpringReport> springReports) override;
	};
}
