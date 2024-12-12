#include "Day12_GardenGroups.h"
#include <map>
#include <queue>
#include <set>
#include "Point.h"

namespace AdventOfCode::Year2024::Day12
{
	GardenGroups::GardenGroups() : DayT(12, "Garden Groups") { }

	uint64_t GardenGroups::ExecutePart1(GridMap gardenMap)
	{
		// Collect all plots in a single set:
		std::set<Point<int>> unassignedPlots;
		gardenMap.Transform([&unassignedPlots](int x, int y, char)
			{
				unassignedPlots.emplace(x, y);
			});

		uint64_t totalFencePrice = 0;

		while (!unassignedPlots.empty())
		{
			// Take the next plot that has not been processed yet:
			auto plot = *unassignedPlots.begin();
			unassignedPlots.erase(plot);
			auto plant = gardenMap.Get(plot);

			// Identify connected plots with a flood fill algorithm
			// while also keeping track of the region's area and perimeter
			uint64_t area = 0;
			uint64_t perimeter = 0;

			std::queue<Point<int>> qFlood;
			qFlood.push(plot);

			while (!qFlood.empty())
			{
				auto p = qFlood.front();
				qFlood.pop();
				++area;

				for (const auto& n : p.GetSurroundingPoints(false))
				{
					// If neighbor plot is not within the map or belongs to another plant, place a fence between them:
					if (!gardenMap.Contains(n) || gardenMap.Get(n) != plant)
						++perimeter;
					// Otherwise (if the plot has not been processed yet) the plot belongs to the current region:
					else if (unassignedPlots.contains(n))
					{
						qFlood.push(n);
						unassignedPlots.erase(n);
					}
				}
			}

			// After the region has been fully identified, calculate and add fence price:
			uint64_t fencePrice = area * perimeter;
			totalFencePrice += fencePrice;
		}

		return totalFencePrice;
	}

	uint64_t GardenGroups::ExecutePart2(GridMap gardenMap)
	{
		// Collect all plots in a single set:
		std::set<Point<int>> unassignedPlots;
		gardenMap.Transform([&unassignedPlots](int x, int y, char)
			{
				unassignedPlots.emplace(x, y);
			});

		uint64_t totalFencePrice = 0;

		while (!unassignedPlots.empty())
		{
			// Take the next plot that has not been processed yet:
			auto plot = *unassignedPlots.begin();
			unassignedPlots.erase(plot);
			auto plant = gardenMap.Get(plot);

			// Identify connected plots with a flood fill algorithm
			// while also keeping track of the region's area.
			uint64_t area = 0;
			
			// To find the number of sides, track and count corners of all plots.
			std::map<Point<int>, int> cornerCounts;
			
			// Identify actual corners by counting: real corners occur exactly once (outer corner) 
			// or thrice (inner corner) within the region.
			//
			// outer corner -> +---+---+
			//                 |   |   |
			//                 +---+---+
			//                 |   |\_____ inner corner
			//                 +---+
			//
			// Corners that occur 4 times are within the region and can be ignored.
			//
			// Corners that occur 2 times are either part of the same edge 
			// or are from two plots that only touch diagonally.
			// 
			//           v---------- edge - do not count
			//       +---+---+ 
			//       |   |   |/
			//   +---+---+---+
			//   |   |\_________ diagonal corner - must be counted twice!
			//   +---+

			std::queue<Point<int>> qFlood;
			qFlood.push(plot);

			while (!qFlood.empty())
			{
				auto p = qFlood.front();
				qFlood.pop();
				++area;

				// Coordinates for corners at plot (x,y):
				//
				//   (x,y) +---+ (x+1,y)
				//         |   |
				// (x,y+1) +---+ (x+1,y+1)

				++cornerCounts[{p.X, p.Y}];
				++cornerCounts[{p.X + 1, p.Y}];
				++cornerCounts[{p.X, p.Y + 1}];
				++cornerCounts[{p.X + 1, p.Y + 1}];

				for (const auto& n : p.GetSurroundingPoints(false))
				{
					// If neighbor plot is within the map and belongs to the same plant the plot belongs to the current region:
					if (gardenMap.Contains(n) && gardenMap.Get(n) == plant && unassignedPlots.contains(n))
					{
						qFlood.push(n);
						unassignedPlots.erase(n);
					}
				}
			}

			// Number of actual corners equals number of sides:
			int actualSides = 0;
			for (const auto& [corner, count] : cornerCounts)
			{
				if (count == 1 || count == 3)
					++actualSides;
				else if (count == 2)
				{
					// Check if this corner is at the edge of the map
					// (which means it must an edge of the region also and not an actual corner):
					if (corner.X == 0 || corner.Y == 0 || corner.X == gardenMap.Width() || corner.Y == gardenMap.Height())
						continue;

					// Check if this corner belongs to diagonally opposite plots by comparing plants
					if (gardenMap.Get(corner) == gardenMap.Get(corner.MoveBy(-1, -1)) ||
						gardenMap.Get(corner.MoveXBy(-1)) == gardenMap.Get(corner.MoveYBy(-1)))
					{
						actualSides += 2;
					}
				}
			}

			uint64_t fencePrice = area * actualSides;
			totalFencePrice += fencePrice;
		}

		return totalFencePrice;
	}

}
