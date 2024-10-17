#include "Day17_ReservoirResearch.h"
#include "Point.h"
#include "WaterStream.h"
#include <algorithm>
#include <map>
#include <set>
#include <stack>

namespace AdventOfCode::Year2018::Day17
{
	ReservoirResearch::ReservoirResearch() : DayT(17, "Reservoir Research") {}

	std::map<Point<int>, bool> GetWaterTiles(const std::vector<ClayVein>& veins)
	{
		// Collect water tiles by coordinate only (and note if they have settled):
		std::map<Point<int>, bool> waterCoords;

		// Tiles blocking the water flow (clay and settled water):
		std::set<Point<int>> blockingTiles;

		// Split veins into individual tiles and get min/max depth:
		int minDepth = INT32_MAX;
		int maxDepth = 0;

		for (const auto& vein : veins)
		{
			minDepth = std::min(minDepth, vein.YRange.Start);
			maxDepth = std::max(maxDepth, vein.YRange.End);

			for (int y = vein.YRange.Start; y <= vein.YRange.End; ++y)
			{
				for (int x = vein.XRange.Start; x <= vein.XRange.End; ++x)
				{
					blockingTiles.emplace(Point(x, y));
				}
			}
		}

		// Current set of water streams, exploring depth-first, starting at the spring
		std::stack<WaterStream> streams;
		streams.emplace(WaterStream(500, 0));

		// Remember all water tiles between min/max depth with direction they were visited:
		std::set<std::pair<Point<int>, FlowDirection>> waterTiles;

		while (!streams.empty())
		{
			// Remove top water stream from stack:
			auto s = streams.top();
			streams.pop();

			// Check if inside blocked tile
			// (e.g. if in an area where water has settled, or a branched stream created inside a clay vein)
			if (blockingTiles.contains(s.Head))
				continue;

			// Count all tiles reached by water within the valid depth range:
			if (s.Head.Y >= minDepth && s.Head.Y <= maxDepth)
				waterCoords.try_emplace(s.Head, false);

			// Because of gravity, always check down direction first
			bool canMoveDown = !blockingTiles.contains(s.Head.MoveYBy(1));
			auto nextPos = canMoveDown ? s.Head.MoveYBy(1) : s.GetNextHeadPos();

			if (canMoveDown || !blockingTiles.contains(nextPos))
			{
				// Next position is sand, continue current direction
				if (nextPos.Y < minDepth)
				{
					// above min depth, continue without checking / inserting water tile
					canMoveDown ? s.MoveDown() : s.MoveForward();
					streams.emplace(s);
				}
				else if (nextPos.Y > maxDepth)
				{
					// below max depth, do not process further:
					continue;
				}
				else
				{
					// Check if already visited (only when flowing downstream):
					auto [_, wasInserted] = waterTiles.insert(std::make_pair(nextPos, s.FlowDir));
					if (!wasInserted && s.FlowDir == FlowDirection::Down)
						continue;
					else
					{
						canMoveDown ? s.MoveDown() : s.MoveForward();
						streams.emplace(s);
					}
				}
			}
			else
			{
				if (s.FlowDir == FlowDirection::Down)
				{
					// Downward movement is blocked, branch into two streams
					// If both sides are blocked immediately, water will settle,
					// and move head / origin upwards
					// (e.g. when in a reservoir with inner width = 1)

					int blockedSides;
					do
					{
						blockedSides = 0;
						auto [leftBranch, rightBranch] = s.Branch();

						if (!blockingTiles.contains(leftBranch.Head))
							streams.emplace(leftBranch);
						else
							++blockedSides;

						if (!blockingTiles.contains(rightBranch.Head))
							streams.emplace(rightBranch);
						else
							++blockedSides;

						if (blockedSides == 2)
						{
							blockingTiles.insert(s.Head);
							waterCoords[s.Head] = true;

							--s.UpstreamOrigin.Y;
							--s.Head.Y;
						}


					} while (blockedSides == 2);
				}
				else
				{
					// Horizontal movement is blocked, continue in opposite direction:
					s.SetBlockedAndReverse(nextPos.X);

					// If blocked in both directions, water between bound will setlle, otherwise continue:
					if (s.IsBlockedInBothDirs())
					{
						auto settledWaterRange = s.GetBoundedWaterRange();
						for (int x = settledWaterRange.Start; x <= settledWaterRange.End; ++x)
						{
							blockingTiles.insert({ x, s.Head.Y });

							// Also mark as settled
							waterCoords[{ x, s.Head.Y }] = true;
						}

						// Continue downwards from upstream origin:
						streams.emplace(WaterStream(s.UpstreamOrigin));
					}
					else
					{
						// Ignore visited tiles when moving horizontally, because new tiles 
						// may be reached through filled reservoirs:
						waterTiles.insert(std::make_pair(s.Head, s.FlowDir));
						streams.emplace(s);
					}
				}
			}
		}

		return waterCoords;
	}

	uint64_t ReservoirResearch::ExecutePart1(std::vector<ClayVein> veins)
	{
		// Count all water tiles:
		return GetWaterTiles(veins).size();
	}

	uint64_t ReservoirResearch::ExecutePart2(std::vector<ClayVein> veins)
	{
		// Count all settled water tiles:
		auto waterTiles = GetWaterTiles(veins);
		return std::count_if(
			waterTiles.begin(),
			waterTiles.end(),
			[](const std::pair<const Point<int>, bool>& w)
			{
				return w.second;
			});
	}
}