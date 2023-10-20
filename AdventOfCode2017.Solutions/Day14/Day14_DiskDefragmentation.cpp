#include "Day14_DiskDefragmentation.h"
#include "KnotHashCalculator.h"
#include "Point.h"
#include <bit>
#include <bitset>
#include <numeric>
#include <queue>
#include <unordered_set>

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
		const std::string& key = input[0];

		// All used squares in the grid:
		std::unordered_set<Point<int>> usedSquares;
		for (int row = 0; row < 128; ++row)
		{
			auto rowHash = CalculateKnotHash(key + "-" + std::to_string(row));
			int column = 0;
			for (int hashPart : rowHash)
			{
				std::bitset<8> bits(hashPart);

				// Find set bits (check left to right, i.e. from high to low)
				for (int i = 7; i >= 0; --i)
				{
					if (bits.test(i))
						usedSquares.insert({ column, row });

					++column;
				}
			}
		}

		// Find regions:
		uint64_t regionCount = 0;

		std::queue<Point<int>> bfs;
		while (!usedSquares.empty())
		{
			bfs.push(*usedSquares.begin());
			usedSquares.erase(usedSquares.begin());
			++regionCount;

			while (!bfs.empty())
			{
				auto p = bfs.front();
				bfs.pop();

				for (auto&& adjacentPoint : p.GetSurroundingPoints(false))
				{
					auto connectedPoint = usedSquares.find(adjacentPoint);
					if (connectedPoint != usedSquares.end())
					{
						bfs.push(*connectedPoint);
						usedSquares.erase(connectedPoint);
					}
				}
			}
		}

		return regionCount;
	}
}
