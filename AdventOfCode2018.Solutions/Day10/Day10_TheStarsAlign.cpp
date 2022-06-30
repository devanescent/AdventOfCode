#include "Day10_TheStarsAlign.h"
#include <algorithm>
#include <iostream>

namespace AdventOfCode::Year2018::Day10
{
	TheStarsAlign::TheStarsAlign() : DayT(10, "The Stars Align")
	{}

	uint64_t TheStarsAlign::ExecutePart1(std::vector<PointOfLight> points)
	{
		bool msgFound = false;
		int secondsPassed = 0;

		// for displaying the points later: minimum (possibly negative) values for x and y coordinates
		int xOffset = 0, yOffset = 0;
		while (!msgFound)
		{
			xOffset = 0;
			yOffset = 0;
			int isolatedPoints = 0;
			for (const auto& p1 : points)
			{
				// Update offsets:
				xOffset = std::min(xOffset, p1.X());
				yOffset = std::min(yOffset, p1.Y());

				auto directNeighbour = std::find_if(points.begin(), points.end(), [p1](const PointOfLight& p2) { return p1.GetDistanceTo(p2) == 1; });
				isolatedPoints += directNeighbour == points.end() ? 1 : 0;
			}

			if ((isolatedPoints * 100 / points.size()) < 10)
			{
				// Less than 10% of all points are isolated: message visible
				msgFound = true;
			}
			else
			{
				// Update all points:
				std::for_each(points.begin(), points.end(), [](PointOfLight& p) { p.UpdatePosition(); });
				secondsPassed++;
			}
		}

		// Build display to read message:
		std::vector<std::string> display;
		for (const auto& p : points)
		{
			size_t xRes = p.X() - xOffset;
			size_t yRes = p.Y() - yOffset;

			if (yRes + 1 > display.size())
			{
				display.resize(yRes + 1);
			}

			if (xRes + 1 > display[yRes].length())
			{
				display[yRes].resize(xRes + 1, ' ');
			}

			display[yRes][xRes] = '#';
		}

		for (const std::string& line : display)
			std::cout << line << "\n";

		return 0;
	}
}
