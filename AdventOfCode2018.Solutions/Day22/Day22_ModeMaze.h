#pragma once
#include "DayT.h"
#include "CaveScanProcessor.h"

namespace AdventOfCode::Year2018::Day22
{
	// ---------------------------------------------------------------------------
	// Day22: Mode Maze
	// ---------------------------------------------------------------------------
	class ModeMaze : public DayT<CaveScanProcessor>
	{
	public:
		ModeMaze();

		uint64_t ExecutePart1(std::vector<CaveScan> scan) override;
		uint64_t ExecutePart2(std::vector<CaveScan> scan) override;
	};
}