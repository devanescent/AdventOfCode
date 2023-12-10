#pragma once
#include "DayTC.h"
#include "PipeMazeProcessor.h"

namespace AdventOfCode::Year2023::Day10
{
	// ---------------------------------------------------------------------------
	// Day10: Pipe Maze
	// ---------------------------------------------------------------------------
	class PipeMaze : public DayTC<PipeMazeProcessor>
	{
	public:
		PipeMaze();

	protected:
		uint64_t ExecutePart1(std::vector<Pipe> pipes, Point<int> startingPoint) override;
		uint64_t ExecutePart2(std::vector<Pipe> pipes, Point<int> startingPoint) override;
	};
}
