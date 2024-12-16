#include "Day16_ReindeerMaze.h"
#include <map>
#include <memory>
#include <queue>
#include <set>
#include "Direction.h"

namespace AdventOfCode::Year2024::Day16
{
	ReindeerMaze::ReindeerMaze() : DayT(16, "Reindeer Maze") { }

	struct MazeProgress
	{
		Point<int> Position;
		Direction Dir;
		uint64_t Score = 0;

		// Include as a pointer to avoid copying within the priority_queue
		std::set<Point<int>>* Path = nullptr;

		MazeProgress(Point<int> pos, Direction dir, uint64_t score, std::set<Point<int>>* path) :
			Position(std::move(pos)), Dir(dir), Score(score), Path(path)
		{ }

		bool operator<(const MazeProgress& other) const
		{
			// The higher the score, the lower the priority:
			return Score > other.Score;
		}
	};

	uint64_t ReindeerMaze::ExecutePart1(GridMap map)
	{
		auto start = map.Find('S');
		auto end = map.Find('E');

		std::priority_queue<MazeProgress> q;

		// Start facing east:
		q.emplace(start, Direction::Right, 0, nullptr);

		// Remember each position (and direction) already visited:
		std::map<std::pair<Point<int>, Direction>, uint64_t> visitedPaths;

		uint64_t bestScore = 0;
		while (!q.empty())
		{
			auto progress = q.top();
			q.pop();

			// Check if curent position and direction was previously reached with a lower or equal score:
			auto key = std::make_pair(progress.Position, progress.Dir);
			auto visIt = visitedPaths.find(key);
			if (visIt != visitedPaths.end() && visIt->second <= progress.Score)
				continue;
			else
				visitedPaths[key] = progress.Score;

			// Stop if destination was reached:
			if (progress.Position == end)
			{
				bestScore = progress.Score;
				break;
			}

			// Try moving forward:
			Point<int> forwardPos = MoveForward(progress.Position, progress.Dir);
			if (map.Get(forwardPos) != '#')
				q.emplace(forwardPos, progress.Dir, progress.Score + 1, nullptr);

			// Try turning left / right:
			if (map.Get(MoveForward(progress.Position, TurnRight(progress.Dir))) != '#')
				q.emplace(progress.Position, TurnRight(progress.Dir), progress.Score + 1000, nullptr);

			if (map.Get(MoveForward(progress.Position, TurnLeft(progress.Dir))) != '#')
				q.emplace(progress.Position, TurnLeft(progress.Dir), progress.Score + 1000, nullptr);
		}

		return bestScore;
	}

	uint64_t ReindeerMaze::ExecutePart2(GridMap map)
	{
		auto start = map.Find('S');
		auto end = map.Find('E');

		std::priority_queue<MazeProgress> q;

		// Start facing east:
		q.emplace(start, Direction::Right, 0, new std::set<Point<int>>());

		// Remember each position (and direction) already visited
		// and collect all visited positions for best paths:
		std::map<std::pair<Point<int>, Direction>, uint64_t> visitedPaths;
		std::set<Point<int>> bestMazePaths;

		uint64_t bestScore = 0;
		while (!q.empty())
		{
			auto progress = q.top();
			q.pop();

			// Check if curent position and direction was reached with a lower score (equal scores can be continued)
			auto key = std::make_pair(progress.Position, progress.Dir);
			auto visIt = visitedPaths.find(key);
			if (visIt != visitedPaths.end() && visIt->second < progress.Score)
			{
				delete progress.Path;
				continue;
			}
			else
				visitedPaths[key] = progress.Score;

			// Stop if destination was reached:
			if (progress.Position == end)
			{
				if (bestScore == 0)
					bestScore = progress.Score;
				
				if (progress.Score == bestScore)
				{
					// Add end to path and then all the positions to the full set of best paths:
					progress.Path->insert(end);
					bestMazePaths.insert(progress.Path->begin(), progress.Path->end());
				}

				delete progress.Path;
				continue;
			}

			// Try turning left / right (and copy current path contents)
			if (map.Get(MoveForward(progress.Position, TurnRight(progress.Dir))) != '#')
			{
				auto pathCopy = new std::set<Point<int>>(progress.Path->begin(), progress.Path->end());
				q.emplace(progress.Position, TurnRight(progress.Dir), progress.Score + 1000, pathCopy);
			}

			if (map.Get(MoveForward(progress.Position, TurnLeft(progress.Dir))) != '#')
			{
				auto pathCopy = new std::set<Point<int>>(progress.Path->begin(), progress.Path->end());
				q.emplace(progress.Position, TurnLeft(progress.Dir), progress.Score + 1000, pathCopy);
			}

			// Try moving forward:
			Point<int> forwardPos = MoveForward(progress.Position, progress.Dir);
			if (map.Get(forwardPos) != '#')
			{
				// Add current position to path and move forward:
				progress.Path->insert(progress.Position);
				q.emplace(forwardPos, progress.Dir, progress.Score + 1, progress.Path);
			}
			else
				delete progress.Path;
		}

		return bestMazePaths.size();
	}
}
