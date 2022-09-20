#pragma once
#include "Day.h"
#include "CaveMap.h"

namespace AdventOfCode::Year2018::Day22
{
	// ---------------------------------------------------------------------------
	// Day22: Mode Maze
	// ---------------------------------------------------------------------------
	class ModeMaze : public Day
	{
	public:
		ModeMaze();

		uint64_t GetResultOnPart1(std::vector<std::string> input) override;
	};
}