#include "BingoBoard.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2021::Day04
{
	void BingoBoard::AddNumber(int nextNum)
	{
		// (horizonal) lines of the board:
		for (auto& line : Num)
		{
			// each number in the line (via index for checking for winning column):
			for (size_t i = 0; i < line.size(); ++i)
			{
				if (line[i].Value == nextNum)
				{
					line[i].IsMarked = true;
					++NumberOfMarks;
					LastAddedNumber = nextNum;

					// Check if line or corresponding column is complete:
					if (!HasWon)
					{
						HasWon = NumberOfMarks >= 5 && 
							(std::all_of(line.begin(), line.end(), [](const BingoBoardNum& bbNum) { return bbNum.IsMarked; }) ||
							(Num[0][i].IsMarked && Num[1][i].IsMarked && Num[2][i].IsMarked && Num[3][i].IsMarked && Num[4][i].IsMarked));
					}
				}
			}
		}
	}

	uint64_t BingoBoard::CalculateScore()
	{
		// Score of the board: Last added number multiplied by the sum of all unmarked numbers:
		return static_cast<uint64_t>(LastAddedNumber) * std::accumulate(Num.begin(), Num.end(), 0,
			// Sum up all rows:
			[](int totalSum, const std::array<BingoBoardNum, 5>& line)
			{
				return totalSum + std::accumulate(line.begin(), line.end(), 0,
					// Sum up unmarked numbers in each row:
					[](int lineSum, const BingoBoardNum& num) { return lineSum + (num.IsMarked ? 0 : num.Value); }
				);
			}
		);
	}
}