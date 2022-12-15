#include "Day12_HillClimbingAlgorithm.h"
#include "Point.h"
#include <map>
#include <queue>

namespace AdventOfCode::Year2022::Day12
{
	struct MapProgress
	{
		Point<int> Pos;
		int Steps;
		int DistanceToTarget;

		// Sort by steps taken, then by distance to goal:
		// returning true means lower priority
		bool operator<(const MapProgress& other) const
		{
			if (Steps != other.Steps)
				return Steps > other.Steps;
			else
				return DistanceToTarget > other.DistanceToTarget;
		}
	};

	HillClimbingAlgorithm::HillClimbingAlgorithm() : Day(12, "Hill Climbing Algorithm") { }

	Point<int> FindPointOnMap(const std::vector<std::string>& map, char point)
	{
		for (int y = 0; y < map.size(); ++y)
		{
			for (int x = 0; x < map[y].size(); ++x)
			{
				if (map[y][x] == point)
					return { x, y };
			}
		}

		return { -1, -1 };
	}

	uint64_t HillClimbingAlgorithm::GetResultOnPart1(std::vector<std::string> map)
	{
		std::priority_queue<MapProgress> q;
		std::map<Point<int>, int> visited; // Remember positions with minimal steps reached
		
		// Find start / end point:
		auto start = FindPointOnMap(map, 'S');
		auto goal = FindPointOnMap(map, 'E');

		// Overwrite with elevation levels:
		map[start.Y][start.X] = 'a';
		map[goal.Y][goal.X] = 'z';

		// Find shortest path from start to end:
		q.emplace(MapProgress{ start, 0, start.DistanceTo(goal) });
		visited[start] = 0;

		// Add next position:
		auto addNextPos = [&](const MapProgress& mp, Point<int> next)
		{
			// Target elevation is lower or at maximum higher by 1:
			if (map[next.Y][next.X] <= map[mp.Pos.Y][mp.Pos.X] + 1)
			{
				auto vis = visited.find(next);

				// Check if this position has either never been visited before or was visited with more steps:
				if (vis == visited.end() || vis->second > mp.Steps + 1)
				{
					visited[next] = mp.Steps + 1;
					q.emplace(MapProgress{ next, mp.Steps + 1, mp.Pos.DistanceTo(goal) });
				}
			}
		};

		// Search until goal is reached:
		while (!q.empty() && (q.top().Pos.X != goal.X || q.top().Pos.Y != goal.Y))
		{
			MapProgress mp = q.top();
			q.pop();
			
			// Check all four directions:
			if (mp.Pos.X > 0)					addNextPos(mp, mp.Pos.MoveXBy(-1)); // left
			if (mp.Pos.Y > 0)					addNextPos(mp, mp.Pos.MoveYBy(-1)); // up
			if (mp.Pos.X < map[0].size() - 1)	addNextPos(mp, mp.Pos.MoveXBy(+1)); // right
			if (mp.Pos.Y < map.size() - 1)		addNextPos(mp, mp.Pos.MoveYBy(+1)); // down
		}

		return q.top().Steps;
	}

	uint64_t HillClimbingAlgorithm::GetResultOnPart2(std::vector<std::string> map)
	{
		std::priority_queue<MapProgress> q;
		std::map<Point<int>, int> visited; // Remember positions with minimal steps reached

		// Find start / end point:
		auto start = FindPointOnMap(map, 'S');
		auto goal = FindPointOnMap(map, 'E');

		// Overwrite with elevation levels:
		map[start.Y][start.X] = 'a';
		map[goal.Y][goal.X] = 'z';

		// Find shortest path from end to the first point at elevation 'a'
		q.emplace(MapProgress{ goal, 0, 0 });
		visited[start] = 0;

		// Add next position:
		auto addNextPos = [&](const MapProgress& mp, Point<int> next)
		{
			// Go backwards from goal: target elevation is higher or at maximum lower by 1
			if (map[next.Y][next.X] >= map[mp.Pos.Y][mp.Pos.X] - 1)
			{
				auto vis = visited.find(next);

				// Check if this position has either never been visited before or was visited with more steps:
				if (vis == visited.end() || vis->second > mp.Steps + 1)
				{
					visited[next] = mp.Steps + 1;
					q.emplace(MapProgress{ next, mp.Steps + 1, 0 });
				}
			}
		};

		// Search until elevation of level 'a' is reached:
		while (!q.empty() && (map[q.top().Pos.Y][q.top().Pos.X] != 'a'))
		{
			MapProgress mp = q.top();
			q.pop();

			// Check all four directions:
			if (mp.Pos.X > 0)					addNextPos(mp, mp.Pos.MoveXBy(-1)); // left
			if (mp.Pos.Y > 0)					addNextPos(mp, mp.Pos.MoveYBy(-1)); // up
			if (mp.Pos.X < map[0].size() - 1)	addNextPos(mp, mp.Pos.MoveXBy(+1)); // right
			if (mp.Pos.Y < map.size() - 1)		addNextPos(mp, mp.Pos.MoveYBy(+1)); // down
		}

		return q.top().Steps;
	}
}
