#pragma once
#include "DayTC.h"
#include "GridComputingClusterProcessor.h"

namespace AdventOfCode::Year2017::Day22
{
	// ---------------------------------------------------------------------------
	// Day22: Sporifica Virus
	// ---------------------------------------------------------------------------
	enum class NodeState
	{
		Clean,
		Weakened,
		Infected,
		Flagged
	};

	class SporificaVirus : public DayTC<GridComputingClusterProcessor>
	{
	public:
		SporificaVirus();

	protected:
		uint64_t ExecutePart1(std::vector<Point<int>> initialInfectedNodes, Point<int> carrierPos) override;
		uint64_t ExecutePart2(std::vector<Point<int>> initialInfectedNodes, Point<int> carrierPos) override;
	};
}
