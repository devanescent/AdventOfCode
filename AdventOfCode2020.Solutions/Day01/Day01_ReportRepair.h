#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2020::Day01
{
	// ---------------------------------------------------------------------------
	// Day01: ReportRepair 
	// ---------------------------------------------------------------------------
	class ReportRepair : public DayT<int, IntProcessor<IntProcessingMode::ValuePerLine>>
	{
	public:
		ReportRepair(int targetSum);

	protected:
		uint64_t ExecutePart1(std::vector<int> report) override;

	private:
		int m_targetSum;
	};
}