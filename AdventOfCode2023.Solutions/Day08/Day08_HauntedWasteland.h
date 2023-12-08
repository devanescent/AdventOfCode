#pragma once
#include "DayTC.h"
#include "NetworkProcessor.h"

namespace AdventOfCode::Year2023::Day08
{
	// ---------------------------------------------------------------------------
	// Day08: Haunted Wasteland
	// ---------------------------------------------------------------------------
	class HauntedWasteland : public DayTC<NetworkProcessor>
	{
	public:
		HauntedWasteland();

	protected:
		uint64_t ExecutePart1(std::vector<NetworkNode> nodes, std::vector<Direction> directions) override;
		uint64_t ExecutePart2(std::vector<NetworkNode> nodes, std::vector<Direction> directions) override;
	};
}
