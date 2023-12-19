#include "Day17_ClumsyCrucible.h"
#include "Point.h"
#include <map>
#include <queue>

namespace AdventOfCode::Year2023::Day17
{
	ClumsyCrucible::ClumsyCrucible() : Day(17, "Clumsy Crucible") { }

	enum class Direction
	{
		Up, Down, Left, Right
	};

	Point<int> MoveStraight(const Point<int>& loc, Direction lastDir)
	{
		switch (lastDir)
		{
			case Direction::Up:		return loc.MoveYBy(-1);
			case Direction::Down:	return loc.MoveYBy(1);
			case Direction::Left:	return loc.MoveXBy(-1);
			case Direction::Right:	return loc.MoveXBy(1);
		}
	}

	Point<int> TurnLeft(const Point<int>& loc, Direction lastDir, Direction& nextDir)
	{
		switch (lastDir)
		{
			case Direction::Up:
				nextDir = Direction::Left;
				return loc.MoveXBy(-1);
			case Direction::Down:
				nextDir = Direction::Right;
				return loc.MoveXBy(1);
			case Direction::Left:
				nextDir = Direction::Down;
				return loc.MoveYBy(1);
			case Direction::Right:
				nextDir = Direction::Up;
				return loc.MoveYBy(-1);
		}
	}

	Point<int> TurnRight(const Point<int>& loc, Direction lastDir, Direction& nextDir)
	{
		switch (lastDir)
		{
			case Direction::Up:
				nextDir = Direction::Right;
				return loc.MoveXBy(1);
			case Direction::Down:
				nextDir = Direction::Left;
				return loc.MoveXBy(-1);
			case Direction::Left:
				nextDir = Direction::Up;
				return loc.MoveYBy(-1);
			case Direction::Right:
				nextDir = Direction::Down;
				return loc.MoveYBy(1);
		}
	}

	// Key for map of visited states to check if current state has been reached before
	struct ProgressKey
	{
		Point<int> Location;
		Direction LastDirection;
		int StraightSteps;

		std::strong_ordering operator<=>(const ProgressKey&) const = default;
		bool operator<(const ProgressKey& other) const { return (*this <=> other) < 0; }
	};

	struct Progress
	{
		ProgressKey Key;

		// for ordering in priority queue
		int HeatLoss;
		int DistanceToTarget;

		bool operator<(const Progress& other) const
		{
			// Higher distance to target and higher heat loss means less priority
			if (DistanceToTarget != other.DistanceToTarget)
				return DistanceToTarget > other.DistanceToTarget;
			else
				return HeatLoss > other.HeatLoss;
		}
	};

	uint64_t FindMinimalHeatLossPath(const std::vector<std::string>& cityMap, const std::vector<ProgressKey>& initialStates, int minStraightSteps, int maxStraightSteps)
	{
		uint64_t minHeatLoss = UINT64_MAX;

		int mapWidth = cityMap[0].length();
		int mapHeight = cityMap.size();
		Point<int> end{ mapWidth - 1, mapHeight - 1 };

		std::map<ProgressKey, int> visitedPoints; // Visited states with their respective heat loss
		std::priority_queue<Progress> q;

		for (const auto& initialState : initialStates)
			q.emplace(initialState, 0, initialState.Location.DistanceTo(end));

		while (!q.empty())
		{
			Progress currentProgress = q.top();
			q.pop();

			auto visitedIt = visitedPoints.find(currentProgress.Key);
			if (visitedIt == visitedPoints.end())
			{
				// State not visited before:
				visitedPoints[currentProgress.Key] = currentProgress.HeatLoss;
			}
			else
			{
				// Current state has been visited before...
				if (visitedIt->second > currentProgress.HeatLoss)
				{
					// ... and was reached in better conditions:
					visitedIt->second = currentProgress.HeatLoss;
				}
				else
				{
					// ... and was reached in worse conditions: do not process further
					continue;
				}
			}

			if (currentProgress.Key.Location == end)
			{
				minHeatLoss = std::min(minHeatLoss, (uint64_t)currentProgress.HeatLoss);
				continue;
			}

			Point<int> next;
			if (currentProgress.Key.StraightSteps < maxStraightSteps)
			{
				next = MoveStraight(currentProgress.Key.Location, currentProgress.Key.LastDirection);
				if (next.CheckBounds(mapWidth, mapHeight))
				{
					auto nextKey = ProgressKey{ next, currentProgress.Key.LastDirection, currentProgress.Key.StraightSteps + 1 };
					q.emplace(
						nextKey,
						currentProgress.HeatLoss + (cityMap[next.Y][next.X] - '0'),
						next.DistanceTo(end));
				}
			}

			// Turn left / right:
			Direction nextDir;
			next = TurnRight(currentProgress.Key.Location, currentProgress.Key.LastDirection, nextDir);

			int currentHeatLoss = currentProgress.HeatLoss;
			int currentStraightSteps = 0;
			while (next.CheckBounds(mapWidth, mapHeight))
			{
				currentHeatLoss += (cityMap[next.Y][next.X] - '0');
				++currentStraightSteps;

				// Move the minimum amount of required steps after turn:
				if (currentStraightSteps < minStraightSteps)
					next = MoveStraight(next, nextDir);
				else
					break;
			}

			if (currentStraightSteps == minStraightSteps)
			{
				auto nextKey = ProgressKey{ next, nextDir, minStraightSteps };
				q.emplace(
					nextKey,
					currentHeatLoss,
					next.DistanceTo(end));
			}

			// Turn left:
			next = TurnLeft(currentProgress.Key.Location, currentProgress.Key.LastDirection, nextDir);
			currentHeatLoss = currentProgress.HeatLoss;
			currentStraightSteps = 0;
			while (next.CheckBounds(mapWidth, mapHeight))
			{
				currentHeatLoss += (cityMap[next.Y][next.X] - '0');
				++currentStraightSteps;

				// Move the minimum amount of required steps after turn:
				if (currentStraightSteps < minStraightSteps)
					next = MoveStraight(next, nextDir);
				else
					break;
			}

			if (currentStraightSteps == minStraightSteps)
			{
				auto nextKey = ProgressKey{ next, nextDir, minStraightSteps };
				q.emplace(
					nextKey,
					currentHeatLoss,
					next.DistanceTo(end));
			}
		}

		return minHeatLoss;
	}

	uint64_t ClumsyCrucible::ExecutePart1(std::vector<std::string> cityMap)
	{
		std::vector<ProgressKey> initialStates;
		initialStates.emplace_back(Point<int>(0, 0), Direction::Right, 0);

		return FindMinimalHeatLossPath(cityMap, initialStates, 1, 3);
	}

	uint64_t ClumsyCrucible::ExecutePart2(std::vector<std::string> cityMap)
	{
		// To avoid handling the start as a special case for movement (must make 4 steps despite not taking a turn)
		// start in the following two states:
		std::vector<ProgressKey> initialStates;
		initialStates.emplace_back(Point<int>(0, 0), Direction::Up, 0);   // -> only valid move is a right turn (moving right)
		initialStates.emplace_back(Point<int>(0, 0), Direction::Left, 0); // -> only valid move is a left turn (moving down)

		return FindMinimalHeatLossPath(cityMap, initialStates, 4, 10);
	}
}
