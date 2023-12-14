#include "Day14_ParabolicReflectorDish.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2023::Day14
{
	ParabolicReflectorDish::ParabolicReflectorDish() : DayTC(14, "Parabolic Reflector Dish") { }

	void MoveRocks(const std::vector<Rock*>& allRocks, std::vector<Rock*>& movingRocks, const Platform& platform, int dx, int dy)
	{
		// Sort rocks depending on direction:
		if (dx == 0 && dy == -1)
		{
			// Move north: move in order Y asc, X asc
			std::sort(movingRocks.begin(), movingRocks.end(),
				[](const Rock* r1, const Rock* r2)
				{
					if (r1->Location.Y != r2->Location.Y)
						return r1->Location.Y < r2->Location.Y;
					else
						return r1->Location.X < r2->Location.X;
				});
		}
		else if (dx == 0 && dy == 1)
		{
			// Move north: move in order Y desc, X asc
			std::sort(movingRocks.begin(), movingRocks.end(),
				[](const Rock* r1, const Rock* r2)
				{
					if (r1->Location.Y != r2->Location.Y)
						return r1->Location.Y > r2->Location.Y;
					else
						return r1->Location.X < r2->Location.X;
				});
		}
		else if (dx == -1 && dy == 0)
		{
			// Move west: move in order X asc, Y asc
			std::sort(movingRocks.begin(), movingRocks.end(),
				[](const Rock* r1, const Rock* r2)
				{
					if (r1->Location.X != r2->Location.X)
						return r1->Location.X < r2->Location.X;
					else
						return r1->Location.Y < r2->Location.Y;
				});
		}
		else if (dx == 1 && dy == 0)
		{
			// Move east: move in order X desc, Y asc
			std::sort(movingRocks.begin(), movingRocks.end(),
				[](const Rock* r1, const Rock* r2)
				{
					if (r1->Location.X != r2->Location.X)
						return r1->Location.X > r2->Location.X;
					else
						return r1->Location.Y < r2->Location.Y;
				});
		}


		// Move rocks in the current direction as far as possible:
		for (auto& rock : movingRocks)
		{
			auto occupiedRockIt = allRocks.end();
			while (occupiedRockIt == allRocks.end())
			{
				auto nextLocation = rock->Location.MoveBy(dx, dy);
				if (nextLocation.X < 0 || nextLocation.Y < 0 || nextLocation.X == platform.Width || nextLocation.Y == platform.Height)
					break; // cannot move further

				// Check, if location is already occupied by another rock:
				occupiedRockIt = std::find_if(allRocks.begin(), allRocks.end(), [&nextLocation](const auto rock) { return rock->Location == nextLocation; });
				if (occupiedRockIt == allRocks.end())
				{
					// If position is free, move rock north:
					rock->Location = nextLocation;
				}
			}
		}
	}


	uint64_t ParabolicReflectorDish::ExecutePart1(std::vector<Rock> rocks, Platform platform)
	{
		// Keep separate list of moving rocks:
		// (use pointers, because location updates must be reflected in both lists)
		std::vector<Rock*> allRocks;
		std::vector<Rock*> movingRocks;

		for (Rock& rock : rocks)
		{
			allRocks.push_back(&rock);
			if (rock.Type == RockType::Round)
				movingRocks.push_back(&rock);
		}

		MoveRocks(allRocks, movingRocks, platform, 0, -1);  // north

		// Calculate load:
		return std::accumulate(
			movingRocks.begin(),
			movingRocks.end(),
			0ull,
			[&platform](uint64_t totalLoad, const Rock* rock)
			{
				return totalLoad + (platform.Height - rock->Location.Y);
			});
	}

	uint64_t ParabolicReflectorDish::ExecutePart2(std::vector<Rock> rocks, Platform platform)
	{
		std::vector<Rock*> allRocks;
		std::vector<Rock*> movingRocks;

		for (Rock& rock : rocks)
		{
			allRocks.push_back(&rock);
			if (rock.Type == RockType::Round)
				movingRocks.push_back(&rock);
		}

		// Numbers of cycles to simulate to find repeating pattern in loads:
		int initialCycles = 200;
		std::vector<uint64_t> loads;

		for (int i = 0; i < initialCycles; ++i)
		{
			MoveRocks(allRocks, movingRocks, platform, 0, -1); // north
			MoveRocks(allRocks, movingRocks, platform, -1, 0); // west
			MoveRocks(allRocks, movingRocks, platform, 0, 1); // south
			MoveRocks(allRocks, movingRocks, platform, 1, 0); // east

			// Calculate load:
			loads.push_back(std::accumulate(
				movingRocks.begin(),
				movingRocks.end(),
				0ull,
				[&platform](uint64_t totalLoad, const Rock* rock)
				{
					return totalLoad + (platform.Height - rock->Location.Y);
				}));
		}


		// Detect cycle:
		auto cycleMid = loads.end();
		auto cycleStart = loads.end();

		// Compare two ranges of increasing length
		// -> Move cycle start backwards, until both ranges are equal
		// -----------------------------------------------------------
		//     [a] [b] [c] [d] [e] [f] [g]
		//          ^           ^           ^
		//     <- start     <- mid         end

		bool cycleDetected = false;
		while (!cycleDetected)
		{
			cycleMid -= 1;
			cycleStart -= 2;

			cycleDetected = std::equal(cycleStart, cycleMid, cycleMid);

			if (!cycleDetected && cycleStart == loads.begin())
				break;
		}

		auto cycleLen = cycleDetected ? cycleMid - cycleStart : 0;
		if (cycleLen == 0)
		{
			// no pattern found: not enough iterations simulated for a repeating pattern to emerge...
			return 0ull;
		}
		else
		{
			uint64_t cycleOffset = (1'000'000'000 - initialCycles - 1) % cycleLen;
			return *(cycleStart + cycleOffset);
		}
	}
}
