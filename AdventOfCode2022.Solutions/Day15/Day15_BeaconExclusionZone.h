#pragma once
#include "DayT.h"
#include "SensorProcessor.h"

namespace AdventOfCode::Year2022::Day15
{
	// ---------------------------------------------------------------------------
	// Day15: Beacon Exclusion Zone
	// ---------------------------------------------------------------------------
	class BeaconExclusionZone : public DayT<SensorProcessor>
	{
	public:
		BeaconExclusionZone(int64_t singleRow = 2'000'000);

	protected:
		uint64_t ExecutePart1(std::vector<Sensor> sensors) override;
		uint64_t ExecutePart2(std::vector<Sensor> sensors) override;

	private:
		int64_t m_row; // for part 1
	};
}
