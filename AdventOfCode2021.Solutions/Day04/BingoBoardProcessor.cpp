#include "BingoBoardProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2021::Day04
{
	std::pair<std::vector<BingoBoard>, std::vector<int>> BingoProcessor::Process(std::vector<std::string> input)
	{
		// Erste Zeile: gezogene Nummern
		std::vector<int> drawnNums;
		{
			std::istringstream drawnNumsStr(input[0]);
			std::string numStr;
			while (std::getline(drawnNumsStr, numStr, ','))
			{
				drawnNums.push_back(std::stoi(numStr));
			}
		}

		// Übrige Zeilen: BingoBoards
		std::vector<BingoBoard> boards;
		{
			BingoBoard board;
			int colIx = 0;
			int rowIx = 0;
			for (size_t i = 2; i < input.size(); ++i)	// skip first line (drawn nums) and separating empty line
			{
				if (!input[i].empty())
				{
					// Fill board line:
					std::istringstream boardLineStr(input[i]);
					std::string boardNumStr;

					while (std::getline(boardLineStr, boardNumStr, ' '))
					{
						if (!boardNumStr.empty())	// because multiple spaces are used in board input
						{
							board.Num[rowIx][colIx].Value = std::stoi(boardNumStr);
							++colIx;
						}
					}

					// Next line:
					++rowIx;
					colIx = 0;
				}
				else
				{
					// Board is finished:
					boards.push_back(board);
					colIx = 0;
					rowIx = 0;
				}
			}

			// Last board:
			boards.push_back(board);
		}

		return std::make_pair(boards, drawnNums);
	}
}