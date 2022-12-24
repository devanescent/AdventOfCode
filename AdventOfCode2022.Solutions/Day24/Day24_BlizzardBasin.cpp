#include "Day24_BlizzardBasin.h"
#include <algorithm>
#include <queue>
#include <set>

namespace AdventOfCode::Year2022::Day24
{
	BlizzardBasin::BlizzardBasin() : DayT(24, "Blizzard Basin") { }

	uint64_t TraverseValley(const std::vector<Blizzard>& blizzards, Point<int> start, Point<int> end, int startingMinute)
	{
		struct PathProgress
		{
			Point<int> Pos;
			int MinutesSpent;
			int EstDistanceToTarget;

			PathProgress(Point<int> pos, int minute, int estDistance) :
				Pos(pos), MinutesSpent(minute), EstDistanceToTarget(estDistance)
			{}

			// Less: true if lower priority
			bool operator<(const PathProgress& other) const
			{
				if (EstDistanceToTarget != other.EstDistanceToTarget)
					return other.EstDistanceToTarget < EstDistanceToTarget;
				else
					return other.MinutesSpent < MinutesSpent;
			}
		};

		std::priority_queue<PathProgress> q;
		std::set<std::pair<Point<int>, int>> visited;

		q.emplace(PathProgress(start, startingMinute, start.DistanceTo(end)));

		auto nextMove = [&](Point<int> next, int minute)
		{
			// Check X bounds:
			if (next.X <= 0 || next.X > Blizzard::XMax)
				return;

			// For Y bounds, explicitly allow start and end:
			if (next.Y < 0 || next.Y == 0 && next.X != 1 || next.Y > Blizzard::YMax && next.X != Blizzard::XMax)
				return;

			// Check blizzards:
			if (std::none_of(blizzards.begin(), blizzards.end(),
				[&next, &minute](const Blizzard& b) { return b.GetPosAtTime(minute) == next; }))
			{
				auto currentProgress = std::make_pair(next, minute);
				if (!visited.contains(currentProgress))
				{
					visited.insert(currentProgress);
					q.emplace(next, minute, next.DistanceTo(end));
				}
			}
		};

		// Do not stop at the first time the target is reached, because there may be paths which lead away from the target at first 
		// but still reach it in shorter time because of more favorable blizzards
		uint64_t shortestTime = UINT64_MAX;

		// Fully exhaust the queue:
		while (!q.empty())
		{
			const PathProgress pp = q.top();
			q.pop();

			// Ignore paths taking longer than the current result:
			if (pp.MinutesSpent >= shortestTime)
				continue;
			else if (pp.Pos == end)
				shortestTime = pp.MinutesSpent;

			// Evaluate paths which may lead to a shorter time:
			else if (pp.MinutesSpent + pp.EstDistanceToTarget < shortestTime)
			{
				nextMove(pp.Pos, pp.MinutesSpent + 1); // wait
				nextMove(pp.Pos.MoveYBy(-1), pp.MinutesSpent + 1); // up
				nextMove(pp.Pos.MoveYBy(+1), pp.MinutesSpent + 1); // down
				nextMove(pp.Pos.MoveXBy(-1), pp.MinutesSpent + 1); // left
				nextMove(pp.Pos.MoveXBy(+1), pp.MinutesSpent + 1); // right
			}
		}

		return shortestTime;
	}

	uint64_t BlizzardBasin::ExecutePart1(std::vector<Blizzard> blizzards)
	{
		Point<int> start{ 1,0 };
		Point<int> end{ Blizzard::XMax, Blizzard::YMax + 1 };

		// Travel through the valley once:
		return TraverseValley(blizzards, start, end, 0);
	}

	uint64_t BlizzardBasin::ExecutePart2(std::vector<Blizzard> blizzards)
	{
		Point<int> start{ 1,0 };
		Point<int> end{ Blizzard::XMax, Blizzard::YMax + 1 };

		// Travel through the valley three times:
		// from start to end, back to the start, then back to the end again
		auto firstTripTime = TraverseValley(blizzards, start, end, 0);
		auto secondTripTime = TraverseValley(blizzards, end, start, firstTripTime);
		auto thirdTripTime = TraverseValley(blizzards, start, end, secondTripTime);

		return thirdTripTime;
	}
}
