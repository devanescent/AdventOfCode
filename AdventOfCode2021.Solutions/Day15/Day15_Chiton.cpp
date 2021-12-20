#include "Day15_Chiton.h"
#include "CavePosition.h"
#include <algorithm>
#include <set>

namespace AdventOfCode::Year2021::Day15
{
	Chiton::Chiton() : DayT(15, "Chiton") {}

	// ---------------------------------------------------------------------------
	// Part 1:
	// ---------------------------------------------------------------------------
	uint64_t Chiton::ExecutePart1(std::vector<std::vector<int>> cave)
	{
		// A* algorithm:
		std::set<CavePosition> openList;
		std::set<CavePosition> visitedList;

		int yGoal = static_cast<int>(cave.size()) - 1;
		int xGoal = static_cast<int>(cave[yGoal].size()) - 1;

		openList.emplace(0, 0, 0); // start pos
		visitedList.emplace(0, 0, 0); // start pos

		// Expand position: add all adjacent positions to open list or update metrics:
		auto CheckNeighbour = [&openList, &visitedList, &cave](int x, int y, uint64_t riskSoFar)
		{
			// Check if valid point:
			if (x >= 0 && y >= 0 && y < cave.size() && x < cave[y].size())
			{
				CavePosition nextPos(x, y, riskSoFar + cave[y][x]);

				// Check if new path is less risky:
				auto openIt = openList.find(nextPos);
				if (openIt != openList.end() && nextPos.TotalRiskSoFar < openIt->TotalRiskSoFar)
				{
					// update risk for position:
					openList.erase(openIt);
					openList.insert(nextPos);
				}
				// else check if not yet visited:
				// -> member function find() does not work correctly, because only coordinates are to be considered (not risk) when checking if visited
				else if (std::find_if(visitedList.begin(), visitedList.end(),
					[&nextPos](const CavePosition& cPos)
					{
						return cPos.XPos == nextPos.XPos && cPos.YPos == nextPos.YPos;
					}) == visitedList.end())
				{
					// Position has not been visited yet:
					visitedList.insert(nextPos);
					openList.insert(nextPos);
				}
			}
		};

		// Find path:
		while (!openList.empty())
		{
			const CavePosition currentPos = *openList.begin();

			// if target node is node with minimal risk, end
			if (currentPos.XPos == xGoal && currentPos.YPos == yGoal)
				return currentPos.TotalRiskSoFar;

			openList.erase(currentPos);

			CheckNeighbour(currentPos.XPos, currentPos.YPos - 1, currentPos.TotalRiskSoFar); // Top
			CheckNeighbour(currentPos.XPos + 1, currentPos.YPos, currentPos.TotalRiskSoFar); // Right
			CheckNeighbour(currentPos.XPos, currentPos.YPos + 1, currentPos.TotalRiskSoFar); // Bottom
			CheckNeighbour(currentPos.XPos - 1, currentPos.YPos, currentPos.TotalRiskSoFar); // Left
		}

		// Goal not found:
		return 0ull;
	}
}
