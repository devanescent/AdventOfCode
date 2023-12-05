#pragma once
#include "DayTC.h"
#include "AlmanacProcessor.h"

namespace AdventOfCode::Year2023::Day05
{
	// ---------------------------------------------------------------------------
	// Day05: If You Give A Seed A Fertilizer
	// ---------------------------------------------------------------------------
	class IfYouGiveASeedAFertilizer : public DayTC<AlmanacProcessor>
	{
	public:
		IfYouGiveASeedAFertilizer();

	protected:
		uint64_t ExecutePart1(std::vector<SeedMapping> seedMappings, std::vector<uint64_t> seeds) override;
		uint64_t ExecutePart2(std::vector<SeedMapping> seedMappings, std::vector<uint64_t> seeds) override;
	};
}
