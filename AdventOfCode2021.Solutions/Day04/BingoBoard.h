#pragma once
#include <vector>
#include <string>
#include <optional>

namespace AdventOfCode::Year2021::Day04
{
	/// <summary>
	/// One number in the bingo board - it is either marked or not
	/// </summary>
	struct BingoBoardNum
	{
		BingoBoardNum(int val) : Value(val), IsMarked(false) {}

		int Value;
		bool IsMarked;

		bool operator==(const BingoBoardNum& other) const
		{
			return Value == other.Value && IsMarked == other.IsMarked;
		}
	};

	/// <summary>
	/// A bingo board with the dimensions 5x5
	/// </summary>
	class BingoBoard
	{
	public:
		std::vector<std::vector<BingoBoardNum>> Num;

		bool operator==(const BingoBoard& other) const
		{
			return Num == other.Num;
		}

		std::string ToString() const
		{
			std::string boardStr;

			for (const auto& line : Num)
			{
				char buf[256];
				snprintf(buf, sizeof(buf), "%2d %2d %2d %2d %2d", line[0].Value, line[1].Value, line[2].Value, line[3].Value, line[4].Value);

				if (boardStr.empty())
					boardStr = std::string(buf);
				else
					boardStr += " | " + std::string(buf);
			}

			return boardStr;
		}

		/// <summary>
		/// Inserts the next number in the board and additionally can also calculate the score of the bingo board.
		/// </summary>
		/// <param name="nextNum">: Next number to add to the bingo board</param>
		/// <param name="checkIfWon">: Optionally, also check if the board has won</param>
		/// <returns>
		/// Returns a value if at least one horizontal or vertical line is completely marked. 
		/// Returns no value if the board has not won yet.
		/// </returns>
		std::optional<uint64_t> CalculateScore(int nextNum, bool checkIfWon);

	private:
		/// <summary>
		/// Calculates the sum of all unmarked values of the bingo board.
		/// </summary>
		/// <returns>Sum of all unmarked values.</returns>
		int GetUnmarkedSum();
	};
}