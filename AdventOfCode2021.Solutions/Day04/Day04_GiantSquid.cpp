#include "Day04_GiantSquid.h"

namespace AdventOfCode::Year2021::Day04
{
	GiantSquid::GiantSquid() : DayTC(4, "Giant Squid") {}

	uint64_t GiantSquid::ExecutePart1(std::vector<BingoBoard> boards, std::vector<int> drawnNumbers)
	{
		int numbersUsed = 0;
		for (int n : drawnNumbers)
		{
			++numbersUsed;
			for (BingoBoard& bb : boards)
			{
				// Only check for wins after at least 5 numbers were used:
				if (auto score = bb.CalculateScore(n, numbersUsed >= 5))
					return *score;	// first board that wins
			}
		}

		// No board has won:
		return 0ull;
	}
}
