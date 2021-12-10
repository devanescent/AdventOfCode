#pragma once
#include <utility>
#include <string>

namespace AdventOfCode::Year2021::Day05
{
	class HydroVentLine
	{
	public:
		HydroVentLine(std::pair<int, int> start, std::pair<int, int> end) : m_start(start), m_end(end) {}

		// Check orientation of line:
		bool IsHorizontal() const { return m_start.second == m_end.second; }
		bool IsVertical() const { return m_start.first == m_end.first; }

		// Get a list of all points on a line:
		std::vector<std::pair<int, int>> GetAllPoints() const
		{
			std::vector<std::pair<int, int>> allPoints;

			// Start coordinates of each line
			int xStart = m_start.first;
			int yStart = m_start.second;

			// Horizontal lines:
			if (IsHorizontal())
			{
				// If direction is backwards, swap start and end:
				int xEnd = m_end.first;
				if (xStart > xEnd) std::swap(xStart, xEnd);

				// Collect all points of this line:
				allPoints.reserve(xEnd - xStart + 1);
				for (int x = xStart, y = yStart; x <= xEnd; ++x)
					allPoints.emplace_back(x,y);
			}

			// Vertical lines:
			else if (IsVertical())
			{
				// If direction is backwards, swap start and end:
				int yEnd = m_end.second;
				if (yStart > yEnd) std::swap(yStart, yEnd);

				// Collect all points of this line:
				allPoints.reserve(yEnd - yStart + 1);
				for (int x = xStart, y = yStart; y <= yEnd; ++y)
					allPoints.emplace_back(x, y);
			}

			// Diagonal lines:
			else
			{
				int xEnd = m_end.first;
				int yEnd = m_end.second;

				int xStep = xStart < xEnd ? 1 : -1;
				int yStep = yStart < yEnd ? 1 : -1;

				for (int x = xStart, y = yStart; y <= yEnd, x <= xEnd; x += xStep, y += yStep)
					allPoints.emplace_back(x, y);
			}

			return allPoints;
		}

		bool operator==(const HydroVentLine& other) const
		{
			return m_start == other.m_start && m_end == other.m_end;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "(%d,%d) -> (%d,%d)", m_start.first, m_start.second, m_end.first, m_end.second);
			return std::string(buf);
		}

	private:
		std::pair<int, int> m_start;
		std::pair<int, int> m_end;
	};
}