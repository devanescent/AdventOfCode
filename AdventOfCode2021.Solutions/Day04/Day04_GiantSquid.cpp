#include "Day04_GiantSquid.h"

namespace AdventOfCode::Year2021::Day04
{
	GiantSquid::GiantSquid() : DayTC(4, "Giant Squid") {}

	uint64_t GiantSquid::ExecutePart1(std::vector<BingoBoard> boards, std::vector<int> drawnNumbers)
	{
		for (int n : drawnNumbers)
		{
			for (BingoBoard& bb : boards)
			{
				bb.AddNumber(n);
				if (bb.HasWon)
					return bb.CalculateScore();
			}
		}

		// No board has won:
		return 0ull;
	}

	uint64_t GiantSquid::ExecutePart2(std::vector<BingoBoard> boards, std::vector<int> drawnNumbers)
	{
		for (int n : drawnNumbers)
		{
			for (auto b = boards.begin(); b != boards.end(); /* increment manually done because of erase*/)
			{
				if (!b->HasWon)
				{
					b->AddNumber(n);
					++b;
				}
				else
				{
					// If last board, return its score, otherwise remove from list:
					if (boards.size() == 1)
						return boards[0].CalculateScore();
					else
						b = boards.erase(b);
				}
			}
		}

		// No result:
		return 0ull;
	}
}
