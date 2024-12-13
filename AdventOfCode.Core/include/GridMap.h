#pragma once
#include <optional>
#include <string>
#include <vector>
#include "Point.h"

namespace AdventOfCode
{
	class GridMap
	{
	public:
		GridMap(std::vector<std::string>&& grid) :
			_grid(std::move(grid)),
			_gridWidth(_grid[0].size()), _gridHeight(_grid.size())
		{ }

		int Height() const { return _gridHeight; }
		int Width() const { return _gridWidth; }

		char Get(const Point<int>& p) const
		{
			return _grid[p.Y][p.X];
		}

		bool Contains(const Point<int>& p) const
		{
			return p.IsXBetween(0, _gridWidth - 1) && p.IsYBetween(0, _gridHeight - 1);
		}

		// Finds the first point on the map that is equal to the given value
		std::optional<Point<int>> Find(char value)
		{
			for (int y = 0; y < _gridHeight; ++y)
			{
				for (int x = 0; x < _gridWidth; ++x)
				{
					if (_grid[y][x] == value)
						return Point<int>(x, y);
				}
			}

			return {};
		}

		// Finds a list of points on the map that are equal to the given value
		template<typename OutputIt>
		void Find(OutputIt outIt, char value)
		{
			for (int y = 0; y < _gridHeight; ++y)
			{
				for (int x = 0; x < _gridWidth; ++x)
				{
					if (_grid[y][x] == value)
						*outIt = Point<int>(x, y);
				}
			}
		}

		// Finds a list of points on the map that satisfy the given predicate
		template<typename OutputIt, typename UnaryPred>
		void Find(OutputIt outIt, UnaryPred p)
		{
			for (int y = 0; y < _gridHeight; ++y)
			{
				for (int x = 0; x < _gridWidth; ++x)
				{
					if (p(_grid[y][x]))
						*outIt = Point<int>(x, y);
				}
			}
		}

		// Applies the given transformation operation to all elements of the map
		// Signatur is equal to: void f(int x, int y, char value)
		template<typename TransOp>
		void Transform(TransOp op)
		{
			for (int y = 0; y < _gridHeight; ++y)
			{
				for (int x = 0; x < _gridWidth; ++x)
				{
					op(x, y, _grid[y][x]);
				}
			}
		}

	private:
		std::vector<std::string> _grid;
		int _gridWidth, _gridHeight;
	};
}