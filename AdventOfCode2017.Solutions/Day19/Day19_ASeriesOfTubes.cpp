#include "Day19_ASeriesOfTubes.h"
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
		
		// Move until the end:
		while (MoveStep(input, currentPos, dx, dy, collectedLetters));
		return 0ull;
	}

	uint64_t ASeriesOfTubes::GetResultOnPart2(std::vector<std::string> input)
	{
		// Find starting position in first line:
		auto startIt = std::find(input[0].begin(), input[0].end(), '|');
		Point<int> currentPos{ static_cast<int>(startIt - input[0].begin()), 0 };

		// Assume initial direction: down
		int dx = 0, dy = 1;

		std::string collectedLetters;
		bool reachedEnd = false;

		// Move until the end:
		uint64_t steps = 0;
		while (MoveStep(input, currentPos, dx, dy, collectedLetters))
			++steps;

		return steps;
	}

	// Move a single step forward:
	bool ASeriesOfTubes::MoveStep(std::vector<std::string>& grid, Point<int>& currentPos, int& dx, int& dy, std::string& letters)
	{
		char currentPath = grid[currentPos.Y][currentPos.X];
		if (currentPath == ' ')
		{
			// reached end after moving straight
			return false;
		}
		else if (currentPath == '|' || currentPath == '-')
		{
			// Continue straight:
			currentPos = currentPos.MoveBy(dx, dy);
			return true;
		}
		else if (currentPath != '+')
		{
			// Add letter and continue straight
			letters += currentPath;
			currentPos = currentPos.MoveBy(dx, dy);
			return true;
		}
		else
		{
			if (dy != 0)
			{
				// Moving vertically, check horizontal directions:
				if (currentPos.X > 0)
				{
					char pathToWest = grid[currentPos.Y][currentPos.X - 1];
					if (pathToWest != ' ')
					{
						// continue west:
						dy = 0;
						dx = -1;
						currentPos = currentPos.MoveBy(dx, dy);
						return true;
					}
				}
				if (currentPos.X < grid[0].size() - 1)
				{
					char pathToEast = grid[currentPos.Y][currentPos.X + 1];
					if (pathToEast != ' ')
					{
						// continue east:
						dy = 0;
						dx = 1;
						currentPos = currentPos.MoveBy(dx, dy);
						return true;
					}
				}
			}
			else
			{
				// Moving horizontally, check vertical directions:
				if (currentPos.Y > 0)
				{
					char pathToNorth = grid[currentPos.Y - 1][currentPos.X];
					if (pathToNorth != ' ')
					{
						// continue north:
						dy = -1;
						dx = 0;
						currentPos = currentPos.MoveBy(dx, dy);
						return true;
					}
				}
				if (currentPos.Y < grid.size() - 1)
				{
					char pathToSouth = grid[currentPos.Y + 1][currentPos.X];
					if (pathToSouth != ' ')
					{
						// continue south:
						dy = 1;
						dx = 0;
						currentPos = currentPos.MoveBy(dx, dy);
						return true;
					}
				}
			}

			// Nowhere to turn to
			return false;
		}
	}
}
