#include "Day08_TreetopTreeHouse.h"
#include "Point.h"
#include <set>

namespace AdventOfCode::Year2022::Day08
{
	TreetopTreeHouse::TreetopTreeHouse() : Day(8, "Treetop Tree House") { }

	uint64_t TreetopTreeHouse::GetResultOnPart1(std::vector<std::string> input)
	{
		// Collect coordinates of all visible trees
		std::set<Point<int>> visibleTrees;

		// Ignore trees on the outer border in the following - these are all visible!
		// Rows:
		for (int row = 1; row < input.size() - 1; ++row)
		{
			// Count visible trees from left:
			int leftMax = input[row].front();
			for (int x = 1; x < input[row].length() - 1; ++x)
			{
				if (input[row][x] > leftMax)
				{
					visibleTrees.emplace(x, row);
					leftMax = input[row][x];
				}
			}

			// Count visible trees from right:
			int rightMax = input[row].back();
			for (int x = input[row].length() - 2; x > 0; --x)
			{
				if (input[row][x] > rightMax)
				{
					visibleTrees.emplace(x, row);
					rightMax = input[row][x];
				}
			}
		}

		// Columns:
		for (int col = 1; col < input[0].length() - 1; ++col)
		{
			// From top:
			int topMax = input.front()[col];
			for (int y = 1; y < input.size() - 1; ++y)
			{
				if (input[y][col] > topMax)
				{
					visibleTrees.emplace(col, y);
					topMax = input[y][col];
				}
			}

			// From bottom:
			int bottomMax = input.back()[col];
			for (int y = input.size() - 2; y > 0; --y)
			{
				if (input[y][col] > bottomMax)
				{
					visibleTrees.emplace(col, y);
					bottomMax = input[y][col];
				}
			}
		}

		// Add number of trees at the outer border to number of visible trees from the inner area:
		int outerTrees = input.size() * 2 + input[0].length() * 2 - 4; // Edges minus corners
		return visibleTrees.size() + outerTrees;
	}

	uint64_t TreetopTreeHouse::GetResultOnPart2(std::vector<std::string> input)
	{
		// Ignore trees on outer border, because these will have at least one direction
		// with a viewing distance of 0 which will result in a scenic score of 0
		uint64_t scenicScoreMax = 0;

		// For all trees (except outer border):
		for (int y = 1; y < input.size() - 1; ++y)
		{
			for (int x = 1; x < input[0].length() - 1; ++x)
			{
				// Count visible trees in all directions from this position:
				uint64_t scenicScore = 1;

				// Left:
				for (int _x = x - 1; _x >= 0; --_x)
				{
					if (input[y][_x] >= input[y][x])
					{
						scenicScore *= std::abs(x - _x);
						break;
					}
					else if (_x == 0)
						scenicScore *= x;
				}

				// Right:
				for (int _x = x + 1; _x < input[y].length(); ++_x)
				{
					if (input[y][_x] >= input[y][x])
					{
						scenicScore *= std::abs(x - _x);
						break;
					}
					else if (_x == input[y].length() - 1)
						scenicScore *= (input[y].length() - x - 1);
				}

				// Top:
				for (int _y = y - 1; _y >= 0; --_y)
				{
					if (input[_y][x] >= input[y][x])
					{
						scenicScore *= std::abs(y - _y);
						break;
					}
					else if (_y == 0)
						scenicScore *= y;
				}

				// Bottom:
				for (int _y = y + 1; _y < input.size(); ++_y)
				{
					if (input[_y][x] >= input[y][x])
					{
						scenicScore *= std::abs(y - _y);
						break;
					}
					else if (_y == input.size() - 1)
						scenicScore *= (input.size() - y - 1);
				}

				// Keep maximum score:
				scenicScoreMax = std::max(scenicScore, scenicScoreMax);
			}
		}

		return scenicScoreMax;
	}
}
