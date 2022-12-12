#include "Day12_HillClimbingAlgorithm.h"
#include <map>
#include <queue>

namespace AdventOfCode::Year2022::Day12
{
	struct MapProgress
	{
		int X, Y;
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

	std::pair<int, int> FindPointOnMap(const std::vector<std::string>& map, char point)
	{
		for (int y = 0; y < map.size(); ++y)
		{
			for (int x = 0; x < map[y].size(); ++x)
			{
				if (map[y][x] == point)
					return std::make_pair(x, y);
			}
		}

		return std::make_pair(-1, -1);
	}

	int GetDistance(int x1, int y1, int x2, int y2)
	{
		return std::abs(x1 - x2) + std::abs(y1 - y2);
	}

	uint64_t HillClimbingAlgorithm::GetResultOnPart1(std::vector<std::string> map)
	{
		std::priority_queue<MapProgress> q;
		std::map<std::pair<int, int>, int> visited; // Remember positions with minimal steps reached
		
		// Find start / end point:
		auto start = FindPointOnMap(map, 'S');
		auto goal = FindPointOnMap(map, 'E');

		// Overwrite with elevation levels:
		map[start.second][start.first] = 'a';
		map[goal.second][goal.first] = 'z';

		// Find shortest path from start to end:
		q.emplace(MapProgress{ start.first, start.second, 0, GetDistance(start.first, start.second, goal.first, goal.second) });
		visited[{start.first, start.second}] = 0;

		// Add next position:
		auto addNextPos = [&](const MapProgress& mp, int nextX, int nextY)
		{
			// Target elevation is lower or at maximum higher by 1:
			if (map[nextY][nextX] <= map[mp.Y][mp.X] + 1)
			{
				auto vis = visited.find({ nextX, nextY });

				// Check if this position has either never been visited before or was visited with more steps:
				if (vis == visited.end() || vis->second > mp.Steps + 1)
				{
					visited[{ nextX, nextY }] = mp.Steps + 1;
					q.emplace(MapProgress{ nextX, nextY, mp.Steps + 1, GetDistance(mp.X, mp.Y, goal.first, goal.second) });
				}
			}
		};

		// Search until goal is reached:
		while (!q.empty() && (q.top().X != goal.first || q.top().Y != goal.second))
		{
			MapProgress mp = q.top();
			q.pop();
			
			// Check all four directions:
			if (mp.X > 0)					addNextPos(mp, mp.X - 1, mp.Y); // left
			if (mp.Y > 0)					addNextPos(mp, mp.X, mp.Y - 1); // up
			if (mp.X < map[0].size() - 1)	addNextPos(mp, mp.X + 1, mp.Y); // right
			if (mp.Y < map.size() - 1)		addNextPos(mp, mp.X, mp.Y + 1); // down
		}

		return q.top().Steps;
	}

	uint64_t HillClimbingAlgorithm::GetResultOnPart2(std::vector<std::string> map)
	{
		std::priority_queue<MapProgress> q;
		std::map<std::pair<int, int>, int> visited; // Remember positions with minimal steps reached

		// Find start / end point:
		auto start = FindPointOnMap(map, 'S');
		auto goal = FindPointOnMap(map, 'E');

		// Overwrite with elevation levels:
		map[start.second][start.first] = 'a';
		map[goal.second][goal.first] = 'z';

		// Find shortest path from end to the first point at elevation 'a'
		q.emplace(MapProgress{ goal.first, goal.second, 0, 0 });
		visited[{start.first, start.second}] = 0;

		// Add next position:
		auto addNextPos = [&](const MapProgress& mp, int nextX, int nextY)
		{
			// Go backwards from goal: target elevation is higher or at maximum lower by 1
			if (map[nextY][nextX] >= map[mp.Y][mp.X] - 1)
			{
				auto vis = visited.find({ nextX, nextY });

				// Check if this position has either never been visited before or was visited with more steps:
				if (vis == visited.end() || vis->second > mp.Steps + 1)
				{
					visited[{ nextX, nextY }] = mp.Steps + 1;
					q.emplace(MapProgress{ nextX, nextY, mp.Steps + 1, 0 });
				}
			}
		};

		// Search until elevation of level 'a' is reached:
		while (!q.empty() && (map[q.top().Y][q.top().X] != 'a'))
		{
			MapProgress mp = q.top();
			q.pop();

			// Check all four directions:
			if (mp.X > 0)					addNextPos(mp, mp.X - 1, mp.Y); // left
			if (mp.Y > 0)					addNextPos(mp, mp.X, mp.Y - 1); // up
			if (mp.X < map[0].size() - 1)	addNextPos(mp, mp.X + 1, mp.Y); // right
			if (mp.Y < map.size() - 1)		addNextPos(mp, mp.X, mp.Y + 1); // down
		}

		return q.top().Steps;
	}
}
