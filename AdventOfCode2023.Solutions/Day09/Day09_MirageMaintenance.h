#pragma once
#include "DayT.h"
#include "ValueHistoryProcessor.h"

namespace AdventOfCode::Year2023::Day09
{
	// ---------------------------------------------------------------------------
	// Day09: Mirage Maintenance
	// ---------------------------------------------------------------------------
	class MirageMaintenance : public DayT<ValueHistoryProcessor>
	{
	public:
		MirageMaintenance();

	protected:
		uint64_t ExecutePart1(std::vector<ValueHistory> valueHistories) override;
		uint64_t ExecutePart2(std::vector<ValueHistory> valueHistories) override;
	};
}
