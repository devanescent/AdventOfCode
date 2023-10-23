#include "Day19_ASeriesOfTubes.h"
#include "Point.h"
#include <algorithm>

namespace AdventOfCode::Year2017::Day19
{
	ASeriesOfTubes::ASeriesOfTubes() : Day(19, "A Series of Tubes") { }

	uint64_t ASeriesOfTubes::GetResultOnPart1(std::vector<std::string> input)
	{
		// Find starting position in first line:
		auto startIt = std::find(input[0].begin(), input[0].end(), '|');
		Point<int> currentPos{ static_cast<int>(startIt - input[0].begin()), 0};

		// Assume initial direction: down
		int dx = 0, dy = 1;

		std::string collectedLetters;
		bool reachedEnd = false;
		while (!reachedEnd)
		{
			char currentPath = input[currentPos.Y][currentPos.X];
			if (currentPath == ' ')
			{
				// reached end after moving straight
				reachedEnd = true;
			}
			else if (currentPath == '|' || currentPath == '-')
			{
				// Continue straight:
				currentPos = currentPos.MoveBy(dx, dy);
			}
			else if (currentPath != '+')
			{
				// Add letter and continue straight
				collectedLetters += currentPath;
				currentPos = currentPos.MoveBy(dx, dy);
			}
			else
			{
				if (dy != 0)
				{
					// Moving vertically, check horizontal directions:
					if (currentPos.X > 0)
					{
						char pathToWest = input[currentPos.Y][currentPos.X - 1];
						if (pathToWest != ' ')
						{
							// continue west:
							dy = 0;
							dx = -1;
							currentPos = currentPos.MoveBy(dx, dy);
							continue;
						}
					}
					if (currentPos.X < input[0].size() - 1)
					{
						char pathToEast = input[currentPos.Y][currentPos.X + 1];
						if (pathToEast != ' ')
						{
							// continue east:
							dy = 0;
							dx = 1;
							currentPos = currentPos.MoveBy(dx, dy);
							continue;
						}
					}
				}
				else
				{
					// Moving horizontally, check vertical directions:
					if (currentPos.Y > 0)
					{
						char pathToNorth = input[currentPos.Y - 1][currentPos.X];
						if (pathToNorth != ' ')
						{
							// continue north:
							dy = -1;
							dx = 0;
							currentPos = currentPos.MoveBy(dx, dy);
							continue;
						}
					}
					if (currentPos.Y < input.size() - 1)
					{
						char pathToSouth = input[currentPos.Y + 1][currentPos.X];
						if (pathToSouth != ' ')
						{
							// continue south:
							dy = 1;
							dx = 0;
							currentPos = currentPos.MoveBy(dx, dy);
							continue;
						}
					}
				}

				// Nowhere to turn to
				reachedEnd = true;
			}
		}

		return 0ull;
	}

	uint64_t ASeriesOfTubes::GetResultOnPart2(std::vector<std::string> input)
	{
		return uint64_t();
	}
}
