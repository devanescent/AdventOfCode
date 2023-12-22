#include "Day22_SandSlabs.h"
#include <algorithm>
#include <map>
#include <set>
#include <iostream>

namespace AdventOfCode::Year2023::Day22
{
	SandSlabs::SandSlabs() : DayT(22, "Sand Slabs") { }

	std::map<int, std::set<int>> GetSupporters(std::vector<SandBrick>& sandBricks)
	{
		// Sort by z position (bricks closer to the ground first):
		std::sort(sandBricks.begin(), sandBricks.end());

		// For each brick, list by which brick(s) it is supported
		std::map<int, std::set<int>> supporters;

		// Bricks that have already come to rest (by falling to the ground or resting on other bricks)
		std::vector<SandBrick> restingBricks;

		for (auto brickIt = sandBricks.begin(); brickIt != sandBricks.end(); ++brickIt)
		{
			if (brickIt->IsOnGround())
			{
				restingBricks.push_back(*brickIt);
			}
			else
			{
				// Does this brick fall on any of the already resting bricks?
				auto newZ = -1;
				for (auto restIt = restingBricks.begin(); restIt != restingBricks.end(); ++restIt)
				{
					if (brickIt->WillFallOnTopOf(*restIt))
					{
						if (newZ == -1)
						{
							// First brick the current brick is resting on:
							newZ = restIt->Z2 + 1;
							supporters[brickIt->Num].insert(restIt->Num);
						}
						else
						{
							// If another brick is found, check if it at the same height, then add it to the supporters:
							if (newZ == restIt->Z2 + 1)
								supporters[brickIt->Num].insert(restIt->Num);
						}
					}
				}

				if (newZ == -1)
				{
					// Does not fall on any bricks: will fall to the ground
					newZ = 1;
				}

				auto dz = brickIt->Z2 - brickIt->Z1;
				brickIt->Z1 = newZ;
				brickIt->Z2 = newZ + dz;
				restingBricks.push_back(*brickIt);
			}

			// Higher-up bricks first
			std::sort(restingBricks.begin(), restingBricks.end(), std::greater<>());
		}

		return supporters;
	}

	// Bricks that are essential to the structure: removing them will make other bricks fall
	std::vector<int> GetEssentialBricks(std::map<int, std::set<int>>& supporters, int maxBricks)
	{
		std::vector<int> essentialBricks;
		for (int i = 1; i <= maxBricks; ++i)
		{
			for (const auto& s : supporters)
			{
				// For each brick, find out if there are other bricks solely depending on it
				if (s.second.size() == 1 && s.second.contains(i))
				{
					essentialBricks.push_back(i);
					break;
				}
			}
		}

		return essentialBricks;
	}

	uint64_t SandSlabs::ExecutePart1(std::vector<SandBrick> sandBricks)
	{
		auto supporters = GetSupporters(sandBricks);
		auto essentialBricks = GetEssentialBricks(supporters, sandBricks.size());

		// Any brick that is not essential can be safely disintegrated:
		return sandBricks.size() - essentialBricks.size();
	}

	uint64_t SandSlabs::ExecutePart2(std::vector<SandBrick> sandBricks)
	{
		auto supporters = GetSupporters(sandBricks);
		auto essentialBricks = GetEssentialBricks(supporters, sandBricks.size());

		// Count falling bricks:
		uint64_t fallingBricksTotal = 0;

		for (auto ess : essentialBricks)
		{
			// Find all bricks that depend on the essential brick (and bricks that depend on these, and so on)
			std::set<int> fallingBricks;
			fallingBricks.insert(ess);

			// Iterate through the supporters list, until no more new bricks are found:
			bool foundNew;
			do
			{
				foundNew = false;
				for (auto& s : supporters)
				{
					if (!fallingBricks.contains(s.first) && 
						std::all_of(s.second.begin(), s.second.end(), [&fallingBricks](int supp) { return fallingBricks.contains(supp); }))
					{
						fallingBricks.insert(s.first).second;
						foundNew = true;
					}
				}
			} while (foundNew);

			fallingBricksTotal += fallingBricks.size() - 1; // do not count essential block itself
		}

		return fallingBricksTotal;
	}
}
