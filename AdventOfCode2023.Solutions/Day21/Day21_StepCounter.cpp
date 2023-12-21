#include "Day21_StepCounter.h"
#include <algorithm>
#include <queue>
#include <map>
#include "Point.h"

namespace AdventOfCode::Year2023::Day21
{
	StepCounter::StepCounter() : Day(21, "Step Counter"), m_stepCountPart1(64ull)
	{ }

	// Returns a map of all reachable locations with their (minimal) distance
	std::map<Point<int>, int> GetReachableTiles(const std::vector<std::string>& gardenMap, uint64_t stepCount)
	{
		// Start is center point of map:
		int mapWidth = gardenMap[0].length();
		int mapHeight = gardenMap.size();
		Point<int> start((mapWidth - 1) / 2, (mapHeight - 1) / 2);

		struct Progress
		{
			Point<int> Location;
			int StepCount;
		};


		std::queue<Progress> q;
		q.emplace(Progress{ start, 0 });

		std::map<Point<int>, int> visited; // Each point reached with distance / step count from start

		while (!q.empty())
		{
			Progress p = q.front();
			q.pop();

			auto visIt = visited.find(p.Location);
			if (visIt == visited.end())
				visited.emplace(std::make_pair(p.Location, p.StepCount));
			else
			{
				if (p.StepCount < visIt->second)
					visIt->second = p.StepCount;
				else
					continue;
			}

			if (p.StepCount == stepCount)
				continue;

			for (auto&& nextP : p.Location.GetSurroundingPoints(false))
			{
				if (nextP.CheckBounds(mapWidth, mapHeight) && gardenMap[nextP.Y][nextP.X] != '#')
					q.emplace(Progress{ nextP, p.StepCount + 1 });
			}
		}

		return visited;
	}

	uint64_t StepCounter::ExecutePart1(std::vector<std::string> gardenMap)
	{
		auto reachableTiles = GetReachableTiles(gardenMap, m_stepCountPart1);

		return std::count_if(reachableTiles.begin(), reachableTiles.end(),
			[&](const auto& entry) { return entry.second % 2 == m_stepCountPart1 % 2; });
	}

	uint64_t StepCounter::ExecutePart2(std::vector<std::string> gardenMap)
	{
		// With a step count of 26.501.365 (an odd number), every garden plot with an odd distance from the center 
		// that is equal to or less than the step counter can be reached
		// 
		// Because the given map has odd dimensions (131x131, with (65|65) as starting position), 
		// the tiles with odd distances will be alternating with every repetition of the map.
		// 
		// Placing a checkerboard pattern above the initial map, if the starting tile would be a white tile, 
		// all black tiles could be reached on this map (marked with 'B' below).
		// On the next repetition of the map, all white tiles could be reached (marked with 'W' below), and so on.
		// 
		//                 +---+
		//                 | W |
		//             +---+---+---+
		//             | W | B | W |				(each square is actually the complete map, repeated in every direction)
		//         +---+---+---+---+---+
		//         | W | B | W | B | W |
		//     +---+---+---+---+---+---+---+
		//     | W | B | W | B | W | B | W |
		//     +---+---+---+---+---+---+---+
		//         | W | B | W | B | W |
		//         +---+---+---+---+---+
		//             | W | B | W |
		//             +---+---+---+
		//                 | W |
		//                 +---+

		// Some observations:
		// - There are no stones on the tiles from the center point to the edges.
		// - Step count: 26.501.365 = 202.300 x 131 + 65
		// Therefore it is possible to walk in a straight line in either direction (n, e, s, w). After 26.501.365 steps, 
		// the map will have been repeated 202.300 times, the last position ends up right at the edge


		// Calculate amount of black / white tiles on a black / white map / corner:
		auto reachableTiles = GetReachableTiles(gardenMap, 131);

		uint64_t fullWhite = 0, topLeftWhite = 0, topRightWhite = 0, botLeftWhite = 0, botRightWhite = 0;
		uint64_t fullBlack = 0, topLeftBlack = 0, topRightBlack = 0, botLeftBlack = 0, botRightBlack = 0;

		for (const auto& tileEntry : reachableTiles)
		{
			if (tileEntry.second % 2 == 0)
			{
				++fullWhite;

				// Corners:
				if (tileEntry.first.X + tileEntry.first.Y < 65)
					++topLeftWhite;
				else if (tileEntry.first.Y > 65 && tileEntry.first.X <= (tileEntry.first.Y - 66))
					++botLeftWhite;
				else if (tileEntry.first.X > 65 && tileEntry.first.Y <= (tileEntry.first.X - 66))
					++topRightWhite;
				else if (tileEntry.first.X + tileEntry.first.Y > 195)
					++botRightWhite;
			}
			else
			{
				++fullBlack;

				// Corners:
				if (tileEntry.first.X + tileEntry.first.Y < 65)
					++topLeftBlack;
				else if (tileEntry.first.Y > 65 && tileEntry.first.X <= (tileEntry.first.Y - 66))
					++botLeftBlack;
				else if (tileEntry.first.X > 65 && tileEntry.first.Y <= (tileEntry.first.X - 66))
					++topRightBlack;
				else if (tileEntry.first.X + tileEntry.first.Y > 195)
					++botRightBlack;
			}
		}
		
		// This results in the following area being covered after taking all steps (just one quarter pictured):
		// 
		//      65      (x4, actually x202.300)
		//     <--><------------------------------->
		// +-------+-------+-------+-------+-------+
		// |B      |W      |B      |W      |B      |
		// |   S####################################
		// |   #   |       |       |       |     # |
		// +---#---+-------+-------+-------+---#---+
		// |W  #   |B      |W      |B      |W#
		// |   #   |       |       |       #
		// |   #   |       |       |     # |
		// +---#---+-------+-------+---#---+
		// |B  #   |W      |B      |W#
		// |   #   |       |       #
		// |   #   |       |     # |
		// +---#---+-------+---#---+
		// |W  #   |B      |W#
		// |   #   |       #
		// |   #   |     # |
		// +---#---+---#---+
		// |B  #   |W#
		// |   #   #
		// |   # # |
		// +---#---+

		uint64_t totalTiles = 0;
		uint64_t N = 202'300;

		// The following types of "map" repetitions are found in the resulting area (N = 202.300):
		// 
		// - Maps, where all black / white tiles are reached:
		//   - 1x center map: full black
		
		totalTiles += fullBlack;

		//   - 4x "arm": from the center straight in one direction, except the very last map.
		//     Contains N/2 full white maps and (N/2 - 1) full black maps
		
		totalTiles += 4 * (fullWhite * (N / 2) + fullBlack * (N / 2 - 1));

		//   - Area within each quarter, except for the partial maps along the diagonal edge:
		//     Contains each (N/2 - 1)^2 full black maps and (N/2 - 1)^2 + N/2 - 1 full white maps
		
		totalTiles += 4 * fullBlack * (N / 2 - 1) * (N / 2 - 1);
		totalTiles += 4 * fullWhite * ((N / 2 - 1) * (N / 2 - 1) + (N / 2 - 1));

		//
		// - Maps, where partial amounts of black / white tiles are reached:
		//   - End of each "arm": 4 black maps each missing two corners
		
		totalTiles += fullBlack - topLeftBlack - topRightBlack;  // up
		totalTiles += fullBlack - botLeftBlack - botRightBlack;  // down
		totalTiles += fullBlack - topLeftBlack - botLeftBlack;   // left
		totalTiles += fullBlack - topRightBlack - botRightBlack; // right

		//   - Diagonals: each containing (N-1) black maps missing one corner and N white maps
		//     only consisting of one corner

		totalTiles += (N - 1) * (fullBlack - topLeftBlack);  // top left diagonal
		totalTiles += N * botRightWhite;
		totalTiles += (N - 1) * (fullBlack - topRightBlack); // top right diagonal
		totalTiles += N * botLeftWhite;
		totalTiles += (N - 1) * (fullBlack - botLeftBlack);  // bottom left diagonal
		totalTiles += N * topRightWhite;
		totalTiles += (N - 1) * (fullBlack - botRightBlack); // bottom right diagonal
		totalTiles += N * topLeftWhite;

		return totalTiles;
	}
}
