#include "Day09_SmokeBasin.h"
#include <algorithm>

namespace AdventOfCode::Year2021::Day09
{
	SmokeBasin::SmokeBasin() : DayT(9, "Smoke Basin") {}

	uint64_t SmokeBasin::ExecutePart1(std::vector<std::vector<HeatMapNode>> heatMap)
	{
		uint64_t riskLevel = 0;

		// Check all nodes from top left corner to bottom right corner:
		size_t mapHeight = heatMap.size();
		for (size_t y = 0; y < heatMap.size(); ++y)
		{
			size_t mapWidth = heatMap[y].size();
			for (size_t x = 0; x < heatMap[y].size(); ++x)
			{
				HeatMapNode& currentNode = heatMap[y][x];

				// Check node to the right:
				if (x < (mapWidth - 1))
					currentNode.CompareToNeighbour(heatMap[y][x + 1]);

				// Check node below:
				if (y < (mapHeight - 1))
					currentNode.CompareToNeighbour(heatMap[y + 1][x]);

				// Calculate total risk level:
				if (currentNode.IsMinimum)
					riskLevel += static_cast<uint64_t>(currentNode.Height) + 1;
			}
		}

		return riskLevel;
	}
}


