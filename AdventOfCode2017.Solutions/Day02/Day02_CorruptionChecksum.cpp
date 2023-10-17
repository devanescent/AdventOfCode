#include "Day02_CorruptionChecksum.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2017::Day02
{
	CorruptionChecksum::CorruptionChecksum() : DayT(2, "Corruption Checksum") { }

	uint64_t CorruptionChecksum::ExecutePart1(std::vector<std::vector<int>> spreadsheet)
	{
		return std::accumulate(spreadsheet.begin(), spreadsheet.end(), 0ull,
			[](uint64_t checksum, const auto& row)
			{
				auto minMax = std::minmax_element(row.begin(), row.end());
				auto diff = std::abs((*minMax.first) - (*minMax.second));
				return checksum + diff;
			});
	}

	uint64_t CorruptionChecksum::ExecutePart2(std::vector<std::vector<int>> spreadsheet)
	{
		return std::accumulate(spreadsheet.begin(), spreadsheet.end(), 0ull,
			[&](uint64_t checksum, const auto& row)
			{
				return checksum + GetEvenlyDivisibleResult(row);
			});
	}

	int CorruptionChecksum::GetEvenlyDivisibleResult(const std::vector<int>& row)
	{
		for (int i = 0; i < row.size(); ++i)
		{
			for (int j = 0; j < row.size(); ++j)
			{
				if (i != j && row[i] % row[j] == 0)
				{
					return row[i] / row[j];
				}
			}
		}

		return 0;
	}
}
