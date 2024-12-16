#pragma once
#include "DayT.h"
#include "GridMapProcessor.h"

namespace AdventOfCode::Year2024::Day16
{
	// ---------------------------------------------------------------------------
	// Day16: Reindeer Maze
	// ---------------------------------------------------------------------------
	class ReindeerMaze : public DayT<GridMapProcessor>
	{
	public:
		ReindeerMaze();

	protected:
		uint64_t ExecutePart1(GridMap map) override;
		uint64_t ExecutePart2(GridMap map) override;
	};
}
