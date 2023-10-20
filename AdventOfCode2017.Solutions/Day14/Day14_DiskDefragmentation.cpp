#include "Day14_DiskDefragmentation.h"
#include "KnotHashCalculator.h"
#include <bit>
#include <numeric>

namespace AdventOfCode::Year2017::Day14
{
	DiskDefragmentation::DiskDefragmentation() : Day(14, "Disk Defragmentation") { }

	uint64_t DiskDefragmentation::GetResultOnPart1(std::vector<std::string> input)
	{
		uint64_t totalUsedSquares = 0;
		const std::string& key = input[0];

		for (int row = 0; row < 128; ++row)
		{
			auto rowHash = CalculateKnotHash(key + "-" + std::to_string(row));
			totalUsedSquares += std::accumulate(rowHash.begin(), rowHash.end(), 0ull,
				[](uint64_t usedSquares, int hashVal)
				{
					return usedSquares + std::popcount(static_cast<unsigned char>(hashVal));
				});
		}

		return totalUsedSquares;
	}

	uint64_t DiskDefragmentation::GetResultOnPart2(std::vector<std::string> input)
	{
		return uint64_t();
	}
}
