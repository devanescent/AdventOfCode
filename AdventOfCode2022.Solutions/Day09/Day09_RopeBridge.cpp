#include "Day09_RopeBridge.h"
#include <set>

namespace AdventOfCode::Year2022::Day09
{
	RopeBridge::RopeBridge() : DayT(9, "Rope Bridge") { }

	uint64_t RopeBridge::ExecutePart1(std::vector<RopeMovement> movements)
	{
		// Head and tail initially overlap
		Point<int> head{ 0, 0 };
		Point<int> tail = head;

		// Coordinates visited by the tail:
		std::set<Point<int>> visitedPositions;
		visitedPositions.insert(tail);

		for (const RopeMovement& mvm : movements)
		{
			for (int i = 0; i < mvm.GetDistance(); ++i)
			{
				mvm.MoveHead(head);
				mvm.MoveTail(head, tail);
				visitedPositions.insert(tail);
			}
		}

		return visitedPositions.size();
	}

	uint64_t RopeBridge::ExecutePart2(std::vector<RopeMovement> movements)
	{
		std::vector<Point<int>> knots(10, { 0, 0 });

		// Coordinates visited by the last knot:
		std::set<Point<int>> visitedPositions;
		visitedPositions.insert(knots.back());

		for (const RopeMovement& mvm : movements)
		{
			for (int i = 0; i < mvm.GetDistance(); ++i)
			{
				mvm.MoveHead(knots[0]);

				// Move remaining knots of the rope:
				for (int j = 1; j < 10; ++j)
					mvm.MoveTail(knots[j - 1], knots[j]);

				visitedPositions.insert(knots.back());
			}
		}

		return visitedPositions.size();
	}
}
