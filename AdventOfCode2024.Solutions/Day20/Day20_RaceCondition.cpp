#include "Day20_RaceCondition.h"
#include <map>
#include <queue>

namespace AdventOfCode::Year2024::Day20
{
	RaceCondition::RaceCondition() : DayT(20, "Race Condition") { }

	struct RaceProgress
	{
		Point<int> Position;
		Point<int> PrevPosition;
		int DistanceToEnd;

		bool operator<(const RaceProgress& other) const
		{
			return DistanceToEnd > other.DistanceToEnd;
		}
	};

	std::vector<Point<int>> FindPath(const GridMap& racetrack, const Point<int>& start, const Point<int>& end)
	{
		// Each position visited with the previous location:
		std::map<Point<int>, Point<int>> visited;

		std::priority_queue<RaceProgress> q;
		q.emplace(start, start, start.DistanceTo(end));

		while (!q.empty())
		{
			RaceProgress progress = q.top();
			q.pop();

			visited.emplace(progress.Position, progress.PrevPosition);

			if (progress.Position == end)
				break;

			// Try walking in every direction
			for (const auto& p : progress.Position.GetSurroundingPoints(false))
			{
				if (racetrack.Contains(p) && racetrack.Get(p) == '.' && !visited.contains(p))
					q.emplace(p, progress.Position, p.DistanceTo(end));
			}
		}

		// Backtrack from end to start to find all positions along the path:
		std::vector<Point<int>> path;
		Point<int> currentPos = end;
		while (currentPos != start)
		{
			path.push_back(currentPos);
			currentPos = visited[currentPos];
		}

		// Add the start position itself:
		path.push_back(start);

		// Fix order:
		std::reverse(path.begin(), path.end());
		return path;
	}

	// Count ways to cheat that save at least the required minimum time:
	uint64_t RaceCondition::CountCheats(const std::vector<Point<int>>& path, int maxCheatDuration)
	{
		uint64_t cheats = 0;

		// For each position in the path, find positions in forward direction 
		// that are within the range for the available cheat time.
		// This also ensures each cheat found is unique.
		for (auto p1 = path.begin(); p1 != path.end() - 1; ++p1)
		{
			for (auto p2 = p1 + 1; p2 != path.end(); ++p2)
			{
				// Direct (Manhattan) distance between the two points of the path when cheating:
				auto cheatDistance = p1->DistanceTo(*p2);
				if (cheatDistance <= maxCheatDuration)
				{
					// Normal time it would take when following the path:
					auto normalDistance = (int)std::distance(p1, p2);

					// First comparison is necessary to check if it's actually a cheat!
					if (cheatDistance < normalDistance && (normalDistance - cheatDistance) >= _minTimeSaved)
						++cheats;
				}
			}
		}

		return cheats;
	}


	uint64_t RaceCondition::ExecutePart1(GridMap racetrack)
	{
		// Find shortest path:
		auto start = racetrack.Find('S');
		racetrack.Replace(start, '.');

		auto end = racetrack.Find('E');
		racetrack.Replace(end, '.');

		// Path through the race track in correct order; index of each entry gives the number 
		// of picoseconds it takes to reach that position without cheating
		auto path = FindPath(racetrack, start, end);

		return CountCheats(path, 2);
	}

	uint64_t RaceCondition::ExecutePart2(GridMap racetrack)
	{
		// Find shortest path:
		auto start = racetrack.Find('S');
		racetrack.Replace(start, '.');

		auto end = racetrack.Find('E');
		racetrack.Replace(end, '.');

		// Path through the race track in correct order; index of each entry gives the number 
		// of picoseconds it takes to reach that position without cheating
		auto path = FindPath(racetrack, start, end);

		return CountCheats(path, 20);
	}
}
