#include "Day16_TheFloorWillBeLava.h"
#include <queue>
#include <set>
#include "Beam.h"

namespace AdventOfCode::Year2023::Day16
{
	TheFloorWillBeLava::TheFloorWillBeLava() : Day(16, "The Floor Will Be Lava") { }

	uint64_t CountEnergizedTiles(const std::vector<std::string>& caveMap, Point<int> startPos, int startdx, int startdy)
	{
		std::set<Point<int>> energizedTiles;
		std::queue<Beam> beam;
		std::set<Beam> visitedBeams;

		beam.emplace(startPos, startdx, startdy);

		while (!beam.empty())
		{
			auto currentBeam = beam.front();
			beam.pop();

			if (!visitedBeams.contains(currentBeam))
				visitedBeams.insert(currentBeam);
			else
				continue;

			auto nextBeam = currentBeam.GetNext();
			if (nextBeam.X < 0 || nextBeam.X >= caveMap[0].length() ||
				nextBeam.Y < 0 || nextBeam.Y >= caveMap.size())
			{
				// Outside of map: skip
				continue;
			}
			else
			{
				// Next position is within the map and will be energized:
				energizedTiles.insert(nextBeam);
			}

			switch (caveMap[nextBeam.Y][nextBeam.X])
			{
			case '.':
				// pass-through:
				beam.emplace(nextBeam, currentBeam.dx, currentBeam.dy);
				break;

			case '/':
				if (currentBeam.dx > 0)
				{
					// left to right: move up
					beam.emplace(nextBeam, 0, -1);
				}
				else if (currentBeam.dx < 0)
				{
					// right to left: move down
					beam.emplace(nextBeam, 0, 1);
				}
				else if (currentBeam.dy > 0)
				{
					// top to bottom: move left
					beam.emplace(nextBeam, -1, 0);
				}
				else if (currentBeam.dy < 0)
				{
					// bottom to top: move right
					beam.emplace(nextBeam, 1, 0);
				}
				break;

			case '\\':
				if (currentBeam.dx > 0)
				{
					// left to right: move down
					beam.emplace(nextBeam, 0, 1);
				}
				else if (currentBeam.dx < 0)
				{
					// right to left: move up
					beam.emplace(nextBeam, 0, -1);
				}
				else if (currentBeam.dy > 0)
				{
					// top to bottom: move right
					beam.emplace(nextBeam, 1, 0);
				}
				else if (currentBeam.dy < 0)
				{
					// bottom to top: move left
					beam.emplace(nextBeam, -1, 0);
				}
				break;

			case '|':
				if (currentBeam.dx != 0)
				{
					// Split if moving horizontally
					beam.emplace(nextBeam, 0, 1);
					beam.emplace(nextBeam, 0, -1);
				}
				else
				{
					// pass-through:
					beam.emplace(nextBeam, currentBeam.dx, currentBeam.dy);
				}
				break;

			case '-':
				if (currentBeam.dy != 0)
				{
					// Split if moving vertically
					beam.emplace(nextBeam, 1, 0);
					beam.emplace(nextBeam, -1, 0);
				}
				else
				{
					// pass-through:
					beam.emplace(nextBeam, currentBeam.dx, currentBeam.dy);
				}
				break;
			}
		}

		return energizedTiles.size();
	}

	uint64_t TheFloorWillBeLava::ExecutePart1(std::vector<std::string> caveMap)
	{
		// Start to the left of the starting position, in the right direction:
		return CountEnergizedTiles(caveMap, { -1, 0 }, 1, 0);
	}

	uint64_t TheFloorWillBeLava::ExecutePart2(std::vector<std::string> caveMap)
	{
		uint64_t maxTiles = 0;

		// Start vertically:
		for (int x = 0; x < caveMap[0].length(); ++x)
		{
			// Top: 
			maxTiles = std::max(maxTiles, CountEnergizedTiles(caveMap, { x, -1 }, 0, 1));

			// Bottom:
			maxTiles = std::max(maxTiles, CountEnergizedTiles(caveMap, { x, (int)caveMap.size() }, 0, -1));
		}

		// Start horizontally:
		for (int y = 0; y < caveMap.size(); ++y)
		{
			// Left: 
			maxTiles = std::max(maxTiles, CountEnergizedTiles(caveMap, { -1, y }, 1, 0));

			// Right:
			maxTiles = std::max(maxTiles, CountEnergizedTiles(caveMap, { (int)caveMap[y].length(), y }, -1, 0));
		}

		return maxTiles;
	}
}
