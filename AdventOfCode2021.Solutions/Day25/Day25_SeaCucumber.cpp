#include "Day25_SeaCucumber.h"

namespace AdventOfCode::Year2021::Day25
{
	SeaCucumber::SeaCucumber() : Day(25, "Sea Cucumber") {}

	uint64_t SeaCucumber::GetResultOnPart1(std::vector<std::string> cucumbers)
	{
		bool canMove = true;
		uint64_t stepCount = 0;

		for (; canMove; ++stepCount)
		{
			canMove = false;
			// First, only '>' cucumbers move:
			for (int y = 0; y < cucumbers.size(); ++y)
			{
				bool clearFirstCol = false;
				for (int x = 0; x < cucumbers[0].size(); ++x)
				{
					if (cucumbers[y][x] == '>')
					{
						// Check if space to the east:
						int xEast = (x < cucumbers[y].size() - 1) ? x + 1 : 0;
						if (cucumbers[y][xEast] == '.')
						{
							// Move:
							canMove = true;

							// For the cucumber in the first column, keep it there during the step
							// to check the last column correctly:
							if (x != 0) 
								cucumbers[y][x] = '.'; 
							else 
								clearFirstCol = true;

							cucumbers[y][xEast] = '>';
							++x; // skip the cucumber that just moved so it is not moved again
						}
					}
				}

				if (clearFirstCol)
					cucumbers[y][0] = '.';
			}

			// Afterwards, 'v' cucumbers move:
			// Iterate over columns first so cucumbers do not get moved twice per step
			for (int x = 0; x < cucumbers[0].size(); ++x)
			{
				bool clearFirstRow = false;

				for (int y = 0; y < cucumbers.size(); ++y)
				{
					if (cucumbers[y][x] == 'v')
					{
						// Check if space below:
						int yBelow = (y < cucumbers.size() - 1) ? y + 1 : 0;
						if (cucumbers[yBelow][x] == '.')
						{
							// Move:
							canMove = true;
							
							if (y != 0)
								cucumbers[y][x] = '.';
							else
								clearFirstRow = true;

							cucumbers[yBelow][x] = 'v';
							++y; // skip the cucumber that just moved so it is not moved again
						}
					}
				}

				if (clearFirstRow)
					cucumbers[0][x] = '.';
			}
		}		

		return stepCount;
	}
}