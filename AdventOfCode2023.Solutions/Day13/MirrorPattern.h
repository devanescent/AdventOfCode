#pragma once
#include <string>
#include <vector>

namespace AdventOfCode::Year2023::Day13
{
	class MirrorPattern
	{
	public:
		std::vector<std::string> Data;

		bool FindVerticalMirror(int requiredErrorCount, int& out_colsLeft) const
		{
			for (int col = 0; col < Data[0].length() - 1; ++col)
			{
				int mirrorErrors = 0;
				bool isValidMirror = true; // for early breaks

				// Check across the full height of the pattern, if columns are equal:
				for (int y = 0; y < Data.size(); ++y)
				{
					// From the current column, check columns to the right / left:
					for (int colOffset = 0; colOffset <= col; ++colOffset)
					{
						if ((col + 1 + colOffset) >= Data[y].length())
							break; // column with no respective column of the right

						else if (Data[y][col - colOffset] != Data[y][col + 1 + colOffset])
						{
							++mirrorErrors;
							if (mirrorErrors > requiredErrorCount)
							{
								isValidMirror = false;
								break;
							}
						}

						if (!isValidMirror)
							break;
					}
				}

				if (mirrorErrors == requiredErrorCount)
				{
					// Number of columns to the left of the mirror position:
					out_colsLeft = col + 1;
					return true;
				}
			}

			return false;
		}

		bool FindHorizontalMirror(int requiredErrorCount, int& out_rowsAbove) const
		{
			for (int row = 0; row < Data.size() - 1; ++row)
			{
				int mirrorErrors = 0;
				bool isValidMirror = true;  // for early breaks

				// Check across the full width of the pattern, if rows are equal:
				for (int x = 0; x < Data[row].length(); ++x)
				{
					// From the current row, check rows above / below:
					for (int rowOffset = 0; rowOffset <= row; ++rowOffset)
					{
						if ((row + 1 + rowOffset) >= Data.size())
							break; // row with no respective row at the bottom

						else if (Data[row - rowOffset][x] != Data[row + 1 + rowOffset][x])
						{
							++mirrorErrors;
							if (mirrorErrors > requiredErrorCount)
							{
								isValidMirror = false;
								break;
							}
						}
					}

					if (!isValidMirror)
						break;
				}

				if (mirrorErrors == requiredErrorCount)
				{
					// Number of rows above the mirror position:
					out_rowsAbove = row + 1;
					return true;
				}
			}

			return false;
		}
	};
}
