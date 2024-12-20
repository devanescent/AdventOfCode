#include "Day04_CeresSearch.h"
#include "GridTranspose.h"
#include <array>

namespace AdventOfCode::Year2024::Day04
{
	CeresSearch::CeresSearch() : Day(4, "Ceres Search") { }

	uint64_t CeresSearch::ExecutePart1(std::vector<std::string> wordSearch)
	{
		auto wordSearchWidth = wordSearch[0].length();
		auto wordSearchHeight = wordSearch.size();

		// Search for "XMAS" in horizontal, vertical and diagonal directions.
		// Collect all directions as strings:
		std::vector<std::string> searchLines;
		
		// Keep horizontal lines without modifications:
		searchLines.insert(searchLines.end(), wordSearch.begin(), wordSearch.end());

		// Create vertical lines:
		auto searchCols = transpose(wordSearch);
		searchLines.insert(searchLines.end(), searchCols.begin(), searchCols.end());

		// Create diagonals:
		for (int i = 0; i < wordSearchWidth || i < wordSearchHeight; ++i)
		{
			if (i == 0)
			{
				// Main diagonals:
				std::string d1, d2;
				for (int j = 0; j < wordSearchHeight && j < wordSearchWidth; ++j)
				{
					d1 += wordSearch[j][j];
					d2 += wordSearch[j][wordSearchWidth - j - 1];
				}
				if (d1.length() >= 4) searchLines.emplace_back(d1);
				if (d2.length() >= 4) searchLines.emplace_back(d2);
			}
			else
			{
				// Diagonals above / below the main diagonals:
				std::string d1, d2, d3, d4;

				for (int j = 0; i + j < wordSearchHeight && j < wordSearchWidth; ++j)
				{
					d1 += wordSearch[i + j][j];
					d2 += wordSearch[i + j][wordSearchWidth - j - 1];
				}
				for (int j = 0; j < wordSearchHeight && i + j < wordSearchWidth; ++j)
				{
					d3 += wordSearch[j][i + j];
					d4 += wordSearch[j][wordSearchWidth - (i + j) - 1];
				}
				if (d1.length() >= 4) searchLines.emplace_back(d1);
				if (d2.length() >= 4) searchLines.emplace_back(d2);
				if (d3.length() >= 4) searchLines.emplace_back(d3);
				if (d4.length() >= 4) searchLines.emplace_back(d4);
			}
		}

		// Search "xmas" forwards and backwards in every line:
		std::array<std::string, 2> wordsToFind { "XMAS", "SAMX" };
		uint64_t xmasCount = 0;
		for (const std::string& line : searchLines)
		{
			for (const auto& word : wordsToFind)
			{
				size_t offset = 0;
				while (offset <= line.length() - 4)
				{
					offset = line.find(word, offset);
					if (offset != std::string::npos)
					{
						++xmasCount;
						offset += 4;
					}
				}
			}
		}

		return xmasCount;
	}

	bool IsMAndS(char c1, char c2)
	{
		return (c1 == 'M' && c2 == 'S') || (c1 == 'S' && c2 == 'M');
	}

	uint64_t CeresSearch::ExecutePart2(std::vector<std::string> wordSearch)
	{
		auto wordSearchWidth = wordSearch[0].length();
		auto wordSearchHeight = wordSearch.size();

		uint64_t xmasCount = 0;
		for (int col = 0; col < wordSearchWidth - 2; ++col)
		{
			for (int row = 0; row < wordSearchHeight - 2; ++row)
			{
				// Check if center is 'A'
				if (wordSearch[col + 1][row + 1] == 'A' &&
					// Check both diagonals for 'M' and 'S' in any order:
					IsMAndS(wordSearch[col][row], wordSearch[col + 2][row + 2]) &&
					IsMAndS(wordSearch[col][row + 2], wordSearch[col + 2][row]))
				{
					++xmasCount;
				}
			}
		}

		return xmasCount;
	}
}
