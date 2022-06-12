#include "Day01_ChronalCalibration.h"
#include <numeric>
#include <set>

namespace AdventOfCode::Year2018::Day01
{
	ChronalCalibration::ChronalCalibration() : DayT(1, "Chronal Calibration")
	{}

	uint64_t Day01::ChronalCalibration::ExecutePart1(std::vector<int> freqChanges)
	{
		return std::accumulate(freqChanges.begin(), freqChanges.end(), 0ull);
	}

	uint64_t Day01::ChronalCalibration::ExecutePart2(std::vector<int> freqChanges)
	{
		std::set<int> freqResults;
		int currentFreq = 0;

		// Loop over input until a frequency result occurs twice
		while (true)
		{
			for (int df : freqChanges)
			{
				// Lookup current frequency;
				auto freq = freqResults.find(currentFreq);

				if (freq != freqResults.end())
					return *freq;
				else
					freqResults.insert(currentFreq);

				currentFreq += df;
			}
		}

		return 0ull;
	}
}
