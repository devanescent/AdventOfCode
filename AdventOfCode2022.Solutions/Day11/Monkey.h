#pragma once
#include <queue>
#include <string>

namespace AdventOfCode::Year2022::Day11
{
	class Monkey
	{
	public:
		std::queue<uint64_t> Items;

		int TestDivisor;
		int TargetOnTestTrue;
		int TargetOnTestFalse;
		std::string InspectOp, InspectLhs, InspectRhs;

		int ThrowItemToMonkey(uint64_t item) const
		{
			return (item % TestDivisor == 0)
				? TargetOnTestTrue
				: TargetOnTestFalse;
		}

		uint64_t InspectItem(uint64_t item) const
		{
			uint64_t newWorryLevel = InspectLhs == "old" ? item : std::stoi(InspectLhs);
			
			if (InspectOp == "+")
			{
				newWorryLevel += (InspectRhs == "old" ? item : std::stoi(InspectRhs));
			}
			else if (InspectOp == "*")
			{
				newWorryLevel *= (InspectRhs == "old" ? item : std::stoi(InspectRhs));
			}

			return newWorryLevel;
		}
	};
}
