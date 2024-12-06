#include "Day06_GuardGallivant.h"
#include <set>
#include <map>
#include "Point.h"
#include "Guard.h"

namespace AdventOfCode::Year2024::Day06
{
	GuardGallivant::GuardGallivant() : Day(6, "Guard Gallivant") { }

	uint64_t GuardGallivant::ExecutePart1(std::vector<std::string> input)
	{
		auto mapWidth = input[0].size();
		auto mapHeight = input.size();

		// Find obstacles and initial guard position:
		std::set<Point<int>> obstacles;
		Point<int> guardStartPos;

		for (int y = 0; y < mapHeight; ++y)
		{
			for (int x = 0; x < mapWidth; ++x)
			{
				if (input[y][x] == '#')
					obstacles.emplace(x, y);
				else if (input[y][x] == '^')
					guardStartPos = Point<int>(x, y);
			}
		}

		Guard guard(guardStartPos, Direction::Up);

		// Let the guard walk through the map until he leaves the map's bounds;
		// keep track of all places visited:
		std::set<Point<int>> visitedMap;
		while (guard.IsPosWithinMap(mapHeight, mapWidth))
		{
			visitedMap.insert(guard.Position);

			Point<int> nextPos = guard.GetNextPosition();
			if (!obstacles.contains(nextPos))
			{
				// Not obstructed, move forward:
				guard.Position = nextPos;
			}
			else
			{
				// Turn before the obstacle and continue next turn:
				guard.TurnRight();
			}
		}

		return visitedMap.size();
	}

	uint64_t GuardGallivant::ExecutePart2(std::vector<std::string> input)
	{
		auto mapWidth = input[0].size();
		auto mapHeight = input.size();

		// Find obstacles and initial guard position:
		std::set<Point<int>> obstacles;
		Point<int> guardStartPos;

		for (int y = 0; y < mapHeight; ++y)
		{
			for (int x = 0; x < mapWidth; ++x)
			{
				if (input[y][x] == '#')
					obstacles.emplace(x, y);
				else if (input[y][x] == '^')
					guardStartPos = Point<int>(x, y);
			}
		}

		Guard guard(guardStartPos, Direction::Up);

		// Keep track of places that have been visited:
		std::set<Point<int>> visitedMap;

		// Try each position along the guard's walk if placing a new obstacle there would result in a loop:
		std::set<Point<int>> obstacleOptions;

		while (guard.IsPosWithinMap(mapHeight, mapWidth))
		{
			visitedMap.insert(guard.Position);

			Point<int> nextPos = guard.GetNextPosition();
			if (!obstacles.contains(nextPos))
			{
				// Cannot place obstacle outside of the map or on the path visited so far on the map
				// (otherwise the current position could have never been reached)
				if (nextPos.IsXBetween(0, mapWidth - 1) && nextPos.IsYBetween(0, mapHeight - 1) && !visitedMap.contains(nextPos))
				{
					// Add the (temporary) obstacle and check if the path would loop now:
					auto tempObsIt = obstacles.insert(nextPos).first;
					
					// Continue from this position with the new obstacle and try to find a loop:
					Guard loopChecker = guard;
					if (loopChecker.FindLoop(obstacles, mapHeight, mapWidth))
					{
						obstacleOptions.insert(nextPos);
					}

					// Remove the temporary obstacle again:
					obstacles.erase(tempObsIt);
				}
				guard.Position = nextPos;
			}
			else
			{
				// Turn before the obstacle and continue next turn:
				guard.TurnRight();
			}
		}

		return obstacleOptions.size();
	}
}
