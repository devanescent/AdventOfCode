#include "Day22_ReactorReboot.h"
#include <array>
#include <algorithm>
#include <numeric>
#include <queue>
#include <ranges>

namespace AdventOfCode::Year2021::Day22
{
	ReactorReboot::ReactorReboot() : DayT(22, "Reactor Reboot") {}

	// ---------------------------------------------------------------------------
	// Part 1:
	// ---------------------------------------------------------------------------
	uint64_t ReactorReboot::ExecutePart1(std::vector<RebootStep> steps)
	{
		// Mapping cube coord => core array with positive indices:
		// - Indices -50..-1 => 0..49
		// - Index         0 => 50
		// - Indices +1..+50 => 51..100
		std::array<std::array<std::array<bool, 101>, 101>, 101> core{ false };

		for (const auto& rebootStep : steps)
		{
			if (!rebootStep.IsPartOfInitProcedure())
				continue;
			
			for (auto z = rebootStep.Region.ZRange.Start; z <= rebootStep.Region.ZRange.End; ++z)
			{
				for (auto y = rebootStep.Region.YRange.Start; y <= rebootStep.Region.YRange.End; ++y)
				{
					for (auto x = rebootStep.Region.XRange.Start; x <= rebootStep.Region.XRange.End; ++x)
					{
						core[z+50][y+50][x+50] = rebootStep.NewState == RebootState::on;
					}
				}
			}
		}

		// Count all cells that are 'on':
		uint64_t onCubes = 0;
		for (const auto& layer : core) // z-Coord
		{
			for (const auto& row : layer) // y-Coord
			{
				onCubes += std::count(row.begin(), row.end(), true);
			}
		}

		return onCubes;
	}

	// ---------------------------------------------------------------------------
	// Part 2:
	// ---------------------------------------------------------------------------
	struct OverlapSplitResult
	{
		Cuboid OverlapRegion;
		std::vector<Cuboid> Split1;
		std::vector<Cuboid> Split2;
	};

	// Calculate overlap between to cuboids:
	// - Returns false, if the regions do not overlap.
	// - Otherwise, gets the overlap region, splits the non-overlapping regions 
	//   into smaller cuboids, and returns true.
	bool Split(const Cuboid& c1, const Cuboid& c2, OverlapSplitResult& out_result)
	{
		if (!c1.OverlapsWith(c2))
			return false;

		out_result.OverlapRegion.XRange = c1.XRange.Intersect(c2.XRange);
		out_result.OverlapRegion.YRange = c1.YRange.Intersect(c2.YRange);
		out_result.OverlapRegion.ZRange = c1.ZRange.Intersect(c2.ZRange);


		return true;
	}

	uint64_t ReactorReboot::ExecutePart2(std::vector<RebootStep> steps)
	{
		// All cuboids (and partial cuboids) that make up the regions with state 'on':
		std::vector<Cuboid> onRegions;

		// Process each step:
		for (const auto& rebootStep : steps)
		{
			// Add first region without further checks:
			if (onRegions.empty() && rebootStep.NewState == RebootState::on)
			{
				onRegions.push_back(rebootStep.Region);
				continue;
			}

			if (rebootStep.NewState == RebootState::on)
			{
				// Start processing with the original region, which gets split into smaller parts
				// when overlapping with previous regions:
				std::vector<Cuboid> currentSplit;
				currentSplit.push_back(rebootStep.Region);

				// Compare with all existing regions that are on if there are any overlaps:
				for (const auto& alreadyOn : onRegions)
				{
					// Pre-check to avoid checking multiple times if cuboid was already split:
					if (!rebootStep.Region.OverlapsWith(alreadyOn))
						continue;

					// Add only cuboids that are not already parts of other regions:
					std::vector<Cuboid> nextSplit;
					for (auto& currentRegion : currentSplit)
					{
						if (!currentRegion.Split(alreadyOn, nextSplit))
						{
							// Keep current (sub)region if no split was produced
							// (because this particular part did not overlap with the region currently compared against)
							nextSplit.emplace_back(currentRegion);
						}
					}

					// Update split state of the current reboot step:
					currentSplit = nextSplit;
				}

				// Add the resulting split to the 'on-regions':
				if (!currentSplit.empty())
					onRegions.insert(onRegions.end(), currentSplit.begin(), currentSplit.end());
			}
			else
			{
				// If off, instead split the existing "on-regions" (without the part that gets turned off):
				std::vector<Cuboid> newSplit;

				auto onIt = onRegions.begin();
				while (onIt != onRegions.end())
				{
					// Remove the original cuboid and replace with its split
					if (onIt->Split(rebootStep.Region, newSplit))
						onIt = onRegions.erase(onIt);
					// If no split was produced, keep as before and continue:
					else
						++onIt;
				}

				// Add remaining split (without parts that were turned off) into 'on-regions' again:
				if (!newSplit.empty())
					onRegions.insert(onRegions.end(), newSplit.begin(), newSplit.end());
			}
		}

		// Sum up all 'on-regions':
		return std::accumulate(onRegions.begin(), onRegions.end(), 0ull,
			[](uint64_t cubeCnt, const Cuboid& cuboid)
			{
				return cubeCnt + cuboid.GetCubeCount();
			});
	}
}

