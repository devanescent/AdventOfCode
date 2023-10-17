#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2017::Day05
{
	// ---------------------------------------------------------------------------
	// Day05: A Maze of Twisty Trampolines, All Alike
	// ---------------------------------------------------------------------------
	class AMazeOfTwistyTrampolinesAllAlike : public DayT<IntProcessor<IntProcessingMode::ValuePerLine>>
	{
	public:
		AMazeOfTwistyTrampolinesAllAlike();

		uint64_t ExecutePart1(std::vector<int> jumpOffsets) override;
		uint64_t ExecutePart2(std::vector<int> jumpOffsets) override;
	};
}
