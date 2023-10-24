#include "Day21_FractalArt.h"

#include <algorithm>

#include <numeric>

namespace AdventOfCode::Year2017::Day21
{
	FractalArt::FractalArt() : DayT(21, "Fractal Art") 
	{
		m_sortFuncs =
		{
			[](const Point<int>& a, const Point<int>& b)
				{ return (a.X != b.X) ? a.X < b.X : a.Y < b.Y; },
			[](const Point<int>& a, const Point<int>& b)
				{ return (a.X != b.X) ? a.X > b.X : a.Y < b.Y; },
			[](const Point<int>& a, const Point<int>& b)
				{ return (a.X != b.X) ? a.X < b.X : a.Y > b.Y; },
			[](const Point<int>& a, const Point<int>& b)
				{ return (a.X != b.X) ? a.X > b.X : a.Y > b.Y; },

			[](const Point<int>& a, const Point<int>& b)
				{ return (a.Y != b.Y) ? a.Y < b.Y : a.X < b.X; },
			[](const Point<int>& a, const Point<int>& b)
				{ return (a.Y != b.Y) ? a.Y > b.Y : a.X < b.X; },
			[](const Point<int>& a, const Point<int>& b)
				{ return (a.Y != b.Y) ? a.Y < b.Y : a.X > b.X; },
			[](const Point<int>& a, const Point<int>& b)
				{ return (a.Y != b.Y) ? a.Y > b.Y : a.X > b.X; }
		};
	}

	uint64_t FractalArt::ExecutePart1(std::vector<EnhancementRule> rules)
	{
		std::vector<std::string> grid{ ".#.", "..#", "###" };

		for (int i = 0; i < m_iterations; ++i)
		{
			if (grid.size() % 2 == 0)
				grid = ProcessSubGrids(rules, grid, 2);
			else if (grid.size() % 3 == 0)
				grid = ProcessSubGrids(rules, grid, 3);
		}


		// Count number of bits that are "on" (= '#'):
		return std::accumulate(grid.begin(), grid.end(), 0ull,
			[](uint64_t bitCount, const std::string& row)
			{
				return bitCount + std::count(row.begin(), row.end(), '#');
			});
	}

	uint64_t FractalArt::ExecutePart2(std::vector<EnhancementRule> rules)
	{
		m_iterations = 18;
		return ExecutePart1(std::move(rules));
	}

	std::vector<std::string> FractalArt::ProcessSubGrids(const std::vector<EnhancementRule>& rules, const std::vector<std::string>& grid, int subGridSize)
	{
		size_t newGridSize = (grid.size() / subGridSize) * (subGridSize + 1);
		std::vector<std::string> nextGrid;

		for (int y = 0; y < grid.size(); y += subGridSize)
		{
			// Insert new rows:
			for (int n = 0; n < subGridSize + 1; ++n)
				nextGrid.emplace_back("");

			for (int x = 0; x < grid.size(); x += subGridSize)
			{
				// Collect points from each sub-grid:
				std::vector<Point<int>> subGrid;
				for (int subY = y; subY < y + subGridSize; ++subY)
				{
					for (int subX = x; subX < x + subGridSize; ++subX)
					{
						subGrid.emplace_back(subX, subY);
					}
				}

				// Build patterns in all possible rotations / mirrorings:
				for (const auto& sortFunc : m_sortFuncs)
				{
					std::sort(subGrid.begin(), subGrid.end(), sortFunc);
					std::string inputPattern = std::accumulate(subGrid.begin(), subGrid.end(), std::string(""),
						[subGridSize, &grid](std::string pattern, Point<int>& p)
						{
							if (pattern.size() % (subGridSize + 1) == subGridSize)
								pattern += '/';
							pattern += grid[p.Y][p.X];
							return pattern;
						});

					// Find pattern in rules:
					auto matchingRule = std::find_if(rules.begin(), rules.end(), 
						[&inputPattern](const EnhancementRule& rule)
						{
							return rule.InputPattern == inputPattern;
						});

					if (matchingRule != rules.end())
					{
						// Add output pattern to new grid:
						for (int out = 0; out < subGridSize + 1; ++out)
						{
							// Append to last (subGridSize + 1) lines in grid
							nextGrid[nextGrid.size() - (subGridSize + 1) + out] += matchingRule->OutputPattern[out];
						}

						break;
					}
				}
			}
		}

		return nextGrid;
	}
}
