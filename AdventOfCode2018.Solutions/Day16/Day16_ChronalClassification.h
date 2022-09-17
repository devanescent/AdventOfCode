#pragma once
#include "DayT.h"
#include "ComputationSampleProcessor.h"

namespace AdventOfCode::Year2018::Day16
{
	// ---------------------------------------------------------------------------
	// Day16: Chronal Classification
	// ---------------------------------------------------------------------------
	class ChronalClassification : public DayT<ComputationSampleProcessor>
	{
	public:
		ChronalClassification();

		uint64_t ExecutePart1(std::vector<ComputationSample> samples) override;
	};
}