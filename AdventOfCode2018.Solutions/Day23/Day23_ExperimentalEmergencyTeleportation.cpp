#include "Day23_ExperimentalEmergencyTeleportation.h"
#include "NanobotBox.h"
#include <algorithm>
#include <queue>

namespace AdventOfCode::Year2018::Day23
{
	ExperimentalEmergencyTeleportation::ExperimentalEmergencyTeleportation() : DayT(23, "Experimental Emergency Teleportation") {}


	uint64_t ExperimentalEmergencyTeleportation::ExecutePart1(std::vector<Nanobot> nanobots)
	{
		// 1. Find nanobot with highest signal radius:
		auto nanobotWithHighestRadius = std::max_element(nanobots.begin(), nanobots.end(),
			[](const auto& nanobot1, const auto& nanobot2)
			{ return nanobot1.GetSignalRadius() < nanobot2.GetSignalRadius(); }
		);

		// 2. Find nanobots in range:
		uint64_t nanobotsInRange = std::count_if(nanobots.begin(), nanobots.end(),
			[nanobotWithHighestRadius](const auto& nanobot)
			{
				return nanobot.GetDistanceTo(*nanobotWithHighestRadius) <= nanobotWithHighestRadius->GetSignalRadius();
			}
		);

		return nanobotsInRange;
	}

	uint64_t ExperimentalEmergencyTeleportation::ExecutePart2(std::vector<Nanobot> nanobots)
	{
		// Find bounding box coordinates:
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0, z1 = 0, z2 = 0;
		for (const Nanobot& n : nanobots)
		{
			if (x1 > n.X())
				x1 = n.X();
			else if (x2 < n.X())
				x2 = n.X();

			if (y1 > n.Y())
				y1 = n.Y();
			else if (y2 < n.Y())
				y2 = n.Y();

			if (z1 > n.Z())
				z1 = n.Z();
			else if (z2 < n.Z())
				z2 = n.Z();
		}

		BoundingBox orig(x1, x2, y1, y2, z1, z2);

		std::priority_queue<NanobotBox> prioQ;
		prioQ.emplace(orig, nanobots);

		while (!prioQ.top().IsSingleCoordinate())
		{
			auto newBoxes = prioQ.top().Split(nanobots);
			prioQ.pop();
			for (NanobotBox& nBox : newBoxes)
				prioQ.push(nBox);
		}

		return prioQ.top().GetDistanceFromOrigin();
	}
}