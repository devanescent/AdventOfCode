#include "Day02_CubeConundrum.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2023::Day02
{
	CubeConundrum::CubeConundrum() : DayT(2, "Cube Conundrum") { }

	uint64_t CubeConundrum::ExecutePart1(std::vector<GameRecord> gameRecords)
	{
		return std::accumulate(gameRecords.begin(), gameRecords.end(), 0ull,
			[](uint64_t gameNoSum, const GameRecord& record)
			{
				bool isPossible = std::all_of(record.CubeSets.begin(), record.CubeSets.end(),
					[](const CubeSet& set)
					{
						return set.RedCubes <= 12 && set.GreenCubes <= 13 && set.BlueCubes <= 14;
					});
				return gameNoSum + (isPossible ? record.GameNo : 0);
			});
	}

	uint64_t CubeConundrum::ExecutePart2(std::vector<GameRecord> gameRecords)
	{
		return std::accumulate(gameRecords.begin(), gameRecords.end(), 0ull,
			[](uint64_t gamePowerSum, const GameRecord& record)
			{
				// Number of red cubes required:
				int red = std::max_element(record.CubeSets.begin(), record.CubeSets.end(),
					[](const CubeSet& c1, const CubeSet& c2) { return c1.RedCubes < c2.RedCubes; })
					->RedCubes;

				int blue = std::max_element(record.CubeSets.begin(), record.CubeSets.end(),
					[](const CubeSet& c1, const CubeSet& c2) { return c1.BlueCubes < c2.BlueCubes; })
					->BlueCubes;

				int green = std::max_element(record.CubeSets.begin(), record.CubeSets.end(),
					[](const CubeSet& c1, const CubeSet& c2) { return c1.GreenCubes < c2.GreenCubes; })
					->GreenCubes;

				return gamePowerSum + (red * green * blue);
			});
	}
}
