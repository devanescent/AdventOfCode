#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2021::Day01
{
	// ---------------------------------------------------------------------------
	// Day01: SonarSweep 
	// ---------------------------------------------------------------------------
	class SonarSweep : public DayT<int, IntProcessor<IntProcessingMode::ValuePerLine>>
	{
	public:
		SonarSweep();

	protected:
		uint64_t ExecutePart1(std::vector<int> report) override;
		uint64_t ExecutePart2(std::vector<int> report) override;
	};
}