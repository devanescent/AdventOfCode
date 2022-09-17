#pragma once
#include "DayT.h"
#include "NanobotProcessor.h"

namespace AdventOfCode::Year2018::Day23
{

	// ---------------------------------------------------------------------------
	// Day23: Experimental Emergency Teleportation
	// ---------------------------------------------------------------------------
	class ExperimentalEmergencyTeleportation : public DayT<NanobotProcessor>
	{
	public:
		ExperimentalEmergencyTeleportation();

		uint64_t ExecutePart1(std::vector<Nanobot> nanobots) override;
		uint64_t ExecutePart2(std::vector<Nanobot> nanobots) override;
	};
}