#include "Day09_SmokeBasin.h"
#include <algorithm>
#include <set>
#include <numeric>
#include <functional>

namespace AdventOfCode::Year2021::Day09
{
	SmokeBasin::SmokeBasin() : DayT(9, "Smoke Basin") {}

	// ---------------------------------------------------------------------------
	// Part 1:
	// ---------------------------------------------------------------------------
	uint64_t SmokeBasin::ExecutePart1(HeatMap heatMap)
	{
		uint64_t riskLevel = 0;

		// Check all nodes from top left corner to bottom right corner:
		int mapHeight = static_cast<int>(heatMap.size());
		for (int y = 0; y < mapHeight; ++y)
		{
			int mapWidth = static_cast<int>(heatMap[y].size());
			for (int x = 0; x < mapWidth; ++x)
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

	// ---------------------------------------------------------------------------
	// Part 2:
	// ---------------------------------------------------------------------------
	uint64_t SmokeBasin::ExecutePart2(HeatMap heatMap)
	{
		std::vector<int> basinSizes;

		// Check all nodes from top left corner to bottom right corner:
		int mapHeight = static_cast<int>(heatMap.size());
		for (int y = 0; y < mapHeight; ++y)
		{
			int mapWidth = static_cast<int>(heatMap[y].size());
			for (int x = 0; x < mapWidth; ++x)
			{
				// All nodes lower than 9 are part of a basin:
				if (heatMap[y][x].Height != 9)
				{
					basinSizes.emplace_back(GetBasinSize(heatMap, x, y));
				}
			}
		}

		// Find the largest three elements:
		std::partial_sort(basinSizes.begin(), basinSizes.begin() + 3, basinSizes.end(), std::greater<>());

		// Multiply sizes of the three largest elements:
		return std::accumulate(basinSizes.begin(), basinSizes.begin() + 3, 1ull, std::multiplies<>());
	}

	// ---------------------------------------------------------------------------
	// GetBasinSize
	// ---------------------------------------------------------------------------
	int SmokeBasin::GetBasinSize(HeatMap& map, int x, int y)
	{
		// Nodes yet to visit to determine basin size, starting with the current node:
		// (use std::set to automatically avoid duplications):
		std::set<std::pair<int, int>> basinNodes{ {x,y} };

		// Method to check if an adjacent node is valid and part of the basin:
		auto AddIfPartOfBasin = [&map, &basinNodes](int x, int y)
		{
			if (x >= 0 && y >= 0 && y < map.size() && x < map[y].size() && map[y][x].Height != 9)
				basinNodes.emplace(x, y);
		};

		int basinSize = 0;

		// While still nodes left to visit:
		while (!basinNodes.empty())
		{
			// Pick next node to check:
			const std::pair<int, int>& n = *basinNodes.begin();

			// Check all directions for connected nodes to this basin:
			AddIfPartOfBasin(n.first, n.second - 1); // Top
			AddIfPartOfBasin(n.first + 1, n.second); // Right
			AddIfPartOfBasin(n.first, n.second + 1); // Bottom
			AddIfPartOfBasin(n.first - 1, n.second); // Left

			// Increase basinSize and mark this node as "visited"
			// (by setting it to '9' so it won't be considered again)
			map[n.second][n.first].Height = 9;
			++basinSize;
			basinNodes.erase(n);
		}

		return basinSize;
	}
}


