#include "Day22_ModeMaze.h"
#include "CaveMap.h"
#include <map>
#include <queue>

namespace AdventOfCode::Year2018::Day22
{
	ModeMaze::ModeMaze() : DayT(22, "Mode Maze") {}

	uint64_t ModeMaze::ExecutePart1(std::vector<CaveScan> scan)
	{
		CaveMap caveMap(scan[0].TargetX, scan[0].TargetY, scan[0].Depth);
		return caveMap.GetCaveRiskLevel();
	}

	uint64_t ModeMaze::ExecutePart2(std::vector<CaveScan> scan)
	{
		CaveMap caveMap(scan[0].TargetX, scan[0].TargetY, scan[0].Depth);

		std::priority_queue<CaveProgress> prioQ;
		std::map<std::tuple<int, int, Tool>, int> visited; // List of places visited (with tool) mapped to the minutes it took to reach it

		prioQ.emplace(0, 0, RiskLevel::Rocky, 0, scan[0].TargetX + scan[0].TargetY, Tool::Torch); // Cave mouth
		visited[{0, 0, Tool::Torch}] = 0;

		// While target not reached:
		while (prioQ.top().X != scan[0].TargetX || prioQ.top().Y != scan[0].TargetY)
		{
			auto nextPaths = caveMap.GetPossiblePaths(prioQ.top());
			prioQ.pop();

			for (auto&& next : nextPaths)
			{
				// Check, if a path to this position already exists:
				std::tuple<int, int, Tool> posKey = { next.X, next.Y, next.CurrentTool };
				auto visitedPos = visited.find(posKey);

				// If this position has not been visited yet (with the current tool), add to queue and to "visited" map
				if (visitedPos == visited.end())
				{
					visited[posKey] = next.MinutesSpent;
					prioQ.emplace(next);
				}
				// Or, if the position was reached quicker, instead update the entry in the "visited" map:
				else if (next.MinutesSpent < visitedPos->second)
				{
					visitedPos->second = next.MinutesSpent;
					prioQ.emplace(next);
				}
			}
		}

		return prioQ.top().MinutesSpent;
	}
}