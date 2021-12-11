#pragma once
#include <array>
#include <string>
#include <optional>

namespace AdventOfCode::Year2021::Day04
{
	/// <summary>
	/// One number in the bingo board - it is either marked or not
	/// </summary>
	struct BingoBoardNum
	{
		BingoBoardNum(int num) : Value(num), IsMarked(false) {}
		BingoBoardNum() : BingoBoardNum(0) {}

		int Value = 0;
		bool IsMarked = false;

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
		std::array<std::array<BingoBoardNum, 5>, 5> Num;

		int NumberOfMarks = 0;
		int LastAddedNumber = 0;
		bool HasWon = false;

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

		void AddNumber(int nextNum);
		uint64_t CalculateScore();
	};
}