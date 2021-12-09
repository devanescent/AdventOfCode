#include "BingoBoard.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2021::Day04
{
	std::optional<uint64_t> BingoBoard::CalculateScore(int nextNum, bool checkIfWon)
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

					// Check if line or corresponding column is complete:
					if (checkIfWon && (
						std::all_of(line.begin(), line.end(), [](const BingoBoardNum& bbNum) { return bbNum.IsMarked; }) ||
						(Num[0][i].IsMarked && Num[1][i].IsMarked && Num[2][i].IsMarked && Num[3][i].IsMarked && Num[4][i].IsMarked)
						))
					{
						// Board has won:
						return GetUnmarkedSum() * nextNum;
					}
					else
						return {}; // not won yet:
				}
			}
		}

		// Number not found on the board:
		return {};
	}

	int BingoBoard::GetUnmarkedSum()
	{
		return std::accumulate(Num.begin(), Num.end(), 0, [](int totalSum, const std::vector<BingoBoardNum>& line)
			{
				return totalSum + std::accumulate(line.begin(), line.end(), 0, [](int lineSum, const BingoBoardNum& num)
					{
						return lineSum + (num.IsMarked ? 0 : num.Value);
					});
			});
	}
}