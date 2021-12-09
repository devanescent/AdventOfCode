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
			for (size_t i = 2; i < input.size(); ++i)	// skip first line (drawn nums) and separating empty line
			{
				if (!input[i].empty())
				{
					std::vector<BingoBoardNum> boardLine;

					// Fill board line:
					std::istringstream boardLineStr(input[i]);
					std::string boardNumStr;
					while (std::getline(boardLineStr, boardNumStr, ' '))
					{
						if (!boardNumStr.empty())	// because multiple spaces are used in board input
							boardLine.push_back(std::stoi(boardNumStr));
					}

					// Add line to board:
					board.Num.push_back(boardLine);
				}
				else
				{
					// Board is finished:
					boards.push_back(board);
					board = BingoBoard();
				}
			}

			// Last board:
			boards.push_back(board);
		}

		return std::make_pair(boards, drawnNums);
	}
}