#include "Day03_TobogganTrajectory.h"

namespace AdventOfCode::Year2020::Day03
{
	// ---------------------------------------------------------------------------
	// Day03_TobogganTrajectory
	// Route given as delta values for X and Y
	// ---------------------------------------------------------------------------
	TobogganTrajectory::TobogganTrajectory(int routeX, int routeY) : Day(3, "Toboggan Trajectory"),
		m_routeX(routeX), m_routeY(routeY)
	{}

	// ---------------------------------------------------------------------------
	// GetResult
	// Count the number of trees that are encountered along the trajectory,
	// starting from (0,0)
	// ---------------------------------------------------------------------------
	uint64_t TobogganTrajectory::GetResultOnPart1(std::vector<std::string> mapData)
	{
		if (mapData.empty())
			return 0;

		int mapHeight = (int)mapData.size();
		int mapWidth = (int)(mapHeight > 0 ? mapData[0].length() : 0);

		int posX = 0;
		int treeCount = 0;

		for (int posY = 0; posY < mapHeight; posY += m_routeY)
		{
			if (mapData[posY][posX] == TREE)
				treeCount++;

			posX = (posX + m_routeX) % mapWidth;
		}

		return treeCount;
	}
}