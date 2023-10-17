#include "Day05_AMazeOfTwistyTrampolinesAllAlike.h"

namespace AdventOfCode::Year2017::Day05
{
	AMazeOfTwistyTrampolinesAllAlike::AMazeOfTwistyTrampolinesAllAlike() : DayT(5, "A Maze of Twisty Trampolines, All Alike") { }

	uint64_t AMazeOfTwistyTrampolinesAllAlike::ExecutePart1(std::vector<int> jumpOffsets)
	{
		bool foundExit = false;
		uint64_t steps = 0ull;

		int currentOffsetIndex = 0;
		while (!foundExit)
		{
			++steps;

			int newIndex = currentOffsetIndex + jumpOffsets[currentOffsetIndex];
			if (newIndex < 0 || newIndex >= jumpOffsets.size())
			{
				foundExit = true;
			}
			else
			{
				++jumpOffsets[currentOffsetIndex];
				currentOffsetIndex = newIndex;
			}
		}

		return steps;
	}

	uint64_t AMazeOfTwistyTrampolinesAllAlike::ExecutePart2(std::vector<int> jumpOffsets)
	{
		return uint64_t();
	}
}
