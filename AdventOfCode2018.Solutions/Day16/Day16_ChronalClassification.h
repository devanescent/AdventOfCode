#pragma once
#include "DayTC.h"
#include "ComputationSampleProcessor.h"

namespace AdventOfCode::Year2018::Day16
{
	// ---------------------------------------------------------------------------
	// Day16: Chronal Classification
	// ---------------------------------------------------------------------------
	class ChronalClassification : public DayTC<ComputationSampleProcessor>
	{
	public:
		ChronalClassification();

		uint64_t ExecutePart1(std::vector<ComputationSample> samples, std::vector<Instruction> program) override;
		uint64_t ExecutePart2(std::vector<ComputationSample> samples, std::vector<Instruction> program) override;
	};
}