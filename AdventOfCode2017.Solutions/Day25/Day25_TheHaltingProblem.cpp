#include "Day25_TheHaltingProblem.h"
#include <algorithm>
#include <map>
#include <numeric>

namespace AdventOfCode::Year2017::Day25
{
	TheHaltingProblem::TheHaltingProblem() : DayTC(25, "The Halting Problem") { }

	uint64_t TheHaltingProblem::ExecutePart1(std::vector<Blueprint> blueprints, BlueprintInitializer context)
	{
		int64_t cursorPosition;
		std::map<int64_t, int> tape;

		for (int step = 0; step < context.Steps; ++step)
		{
			// Find applicable blueprint:
			auto blueprint = std::find_if(blueprints.begin(), blueprints.end(),
				[cursorPosition, &context, &tape](const Blueprint& b)
				{
					return b.StateCondition == context.State && b.ValueCondition == tape[cursorPosition];
				});

			tape[cursorPosition] = blueprint->ValueWritten;
			cursorPosition += blueprint->CursorMovement == CursorMovement::Right ? +1 : -1;
			context.State = blueprint->NextState;
		}

		// Diagnostic checksum: count each 1 on tape
		return std::accumulate(tape.begin(), tape.end(), 0ull,
			[](uint64_t count, const std::pair<const int64_t, int>& tapePos)
			{
				return count + tapePos.second;
			});
	}

	uint64_t TheHaltingProblem::ExecutePart2(std::vector<Blueprint> blueprints, BlueprintInitializer context)
	{
		return uint64_t();
	}
}
