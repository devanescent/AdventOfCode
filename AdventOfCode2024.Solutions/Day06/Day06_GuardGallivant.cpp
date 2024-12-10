#include "Day06_GuardGallivant.h"
#include <set>
#include <map>
#include "Point.h"
#include "Guard.h"

namespace AdventOfCode::Year2024::Day06
{
	GuardGallivant::GuardGallivant() : DayT(6, "Guard Gallivant") { }

	uint64_t GuardGallivant::ExecutePart1(GridMap map)
	{
		// Find obstacles and initial guard position:
		std::set<Point<int>> obstacles;
		map.Find(std::inserter(obstacles, obstacles.end()), '#');

		Guard guard(map.Find('^').value(), Direction::Up);

		// Let the guard walk through the map until he leaves the map's bounds;
		// keep track of all places visited:
		std::set<Point<int>> visitedMap;
		while (map.Contains(guard.Position))
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

	uint64_t GuardGallivant::ExecutePart2(GridMap map)
	{
		// Find obstacles and initial guard position:
		std::set<Point<int>> obstacles;
		map.Find(std::inserter(obstacles, obstacles.end()), '#');

		Guard guard(map.Find('^').value(), Direction::Up);

		// Keep track of places that have been visited:
		std::set<Point<int>> visitedMap;

		// Try each position along the guard's walk if placing a new obstacle there would result in a loop:
		std::set<Point<int>> obstacleOptions;

		while (map.Contains(guard.Position))
		{
			visitedMap.insert(guard.Position);

			Point<int> nextPos = guard.GetNextPosition();
			if (!obstacles.contains(nextPos))
			{
				// Cannot place obstacle outside of the map or on the path visited so far on the map
				// (otherwise the current position could have never been reached)
				if (map.Contains(nextPos) && !visitedMap.contains(nextPos))
				{
					// Add the (temporary) obstacle and check if the path would loop now:
					auto tempObsIt = obstacles.insert(nextPos).first;
					
					// Continue from this position with the new obstacle and try to find a loop:
					Guard loopChecker = guard;
					if (loopChecker.FindLoop(obstacles, map.Height(), map.Width()))
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
