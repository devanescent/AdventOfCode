#include "Day03_TobogganTrajectory.h"

namespace AdventOfCode::Year2020::Day03
{
	TobogganTrajectory::TobogganTrajectory() : Day(3, "Toboggan Trajectory") {}

	const char TREE = '#';

	int TobogganTrajectory::CountTreesOnTraversal(const std::vector<std::string>& map, int dx, int dy)
	{
		int mapHeight = static_cast<int>(map.size());
		int mapWidth = static_cast<int>(map[0].length());

		int treeCount = 0;

		// Start position: 0,0
		int posX = 0;
		for (int posY = 0; posY < mapHeight; posY += dy)
		{
			if (map[posY][posX] == TREE)
				++treeCount;

			// "Wrap around" x coordinate:
			posX = (posX + dx) % mapWidth;
		}

		return treeCount;
	}

	uint64_t TobogganTrajectory::GetResultOnPart1(std::vector<std::string> mapData)
	{
		return CountTreesOnTraversal(mapData, 3, 1);
	}

	uint64_t TobogganTrajectory::GetResultOnPart2(std::vector<std::string> mapData)
	{
		return static_cast<uint64_t>(CountTreesOnTraversal(mapData, 1, 1)) *
			   CountTreesOnTraversal(mapData, 3, 1) *
			   CountTreesOnTraversal(mapData, 5, 1) *
			   CountTreesOnTraversal(mapData, 7, 1) *
			   CountTreesOnTraversal(mapData, 1, 2);
	}
}