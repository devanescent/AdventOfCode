#include "CoordinateProcessor.h"
#include <algorithm>

namespace AdventOfCode::Year2018::Day06
{
	std::pair<std::vector<Coord>, BoundingBox> CoordinateProcessor::Process(std::vector<std::string> input)
	{
		std::pair<std::vector<Coord>, BoundingBox> result;
		std::vector<Coord>& coords = result.first;
		BoundingBox& bounds = result.second;

		// Coordinates:
		coords.reserve(input.size());
		for (const std::string& line : input)
		{
			int x = atoi(line.c_str());
			int y = atoi(line.c_str() + line.find(',') + 1);

			coords.emplace_back(x, y);
		}

		// Bounding box:
		auto xBounds = std::minmax_element(coords.begin(), coords.end(),
			[](const Coord& lhs, const Coord& rhs) { return lhs.X < rhs.X; }
		);

		bounds.XMin = xBounds.first->X;
		bounds.XMax = xBounds.second->X;

		auto yBounds = std::minmax_element(coords.begin(), coords.end(),
			[](const Coord& lhs, const Coord& rhs) { return lhs.Y < rhs.Y; }
		);

		bounds.YMin = yBounds.first->Y;
		bounds.YMax = yBounds.second->Y;

		return result;
	}
}
