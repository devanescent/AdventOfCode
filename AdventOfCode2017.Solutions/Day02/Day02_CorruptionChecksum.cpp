#include "Day02_CorruptionChecksum.h"
#include <algorithm>

namespace AdventOfCode::Year2017::Day02
{
	CorruptionChecksum::CorruptionChecksum() : DayT(2, "Corruption Checksum") { }

	uint64_t CorruptionChecksum::ExecutePart1(std::vector<std::vector<int>> spreadsheet)
	{
		uint64_t checksum = 0;
		for (const auto& row : spreadsheet)
		{
			auto minMax = std::minmax_element(row.begin(), row.end());
			auto diff = std::abs((*minMax.first) - (*minMax.second));
			checksum += diff;
		}

		return checksum;
	}

	uint64_t CorruptionChecksum::ExecutePart2(std::vector<std::vector<int>> spreadsheet)
	{
		return uint64_t();
	}
}
