#pragma once
#include "DayTC.h"
#include "PottedPlantProcessor.h"

namespace AdventOfCode::Year2018::Day12
{
	// ---------------------------------------------------------------------------
	// Day 12: Subterranean Sustainability 
	// ---------------------------------------------------------------------------
	class SubterraneanSustainability : public DayTC<PottedPlantProcessor>
	{
	public:
		SubterraneanSustainability();

	protected:
		virtual uint64_t ExecutePart1(PotRow pots, PlantRules rules) override;
		virtual uint64_t ExecutePart2(PotRow pots, PlantRules rules) override;
	};
}