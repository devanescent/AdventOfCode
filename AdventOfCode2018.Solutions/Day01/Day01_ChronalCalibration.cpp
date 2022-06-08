#include "Day01_ChronalCalibration.h"
#include <numeric>

namespace AdventOfCode::Year2018::Day01
{
	ChronalCalibration::ChronalCalibration() : DayT(1, "Chronal Calibration")
	{}

	uint64_t Day01::ChronalCalibration::ExecutePart1(std::vector<int> freqChanges)
	{
		return std::accumulate(freqChanges.begin(), freqChanges.end(), 0ull);
	}
}
