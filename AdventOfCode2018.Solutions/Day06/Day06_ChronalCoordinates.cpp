#include "Day06_ChronalCoordinates.h"
#include "Coord.h"

#include <algorithm>
#include <map>
#include <numeric>

namespace AdventOfCode::Year2018::Day06
{
	ChronalCoordinates::ChronalCoordinates(int distanceLimit) : DayTC(6, "Chronal Coordinates"), m_distanceLimit(distanceLimit) {}

	const int INFINITE_AREA = -1;

	uint64_t ChronalCoordinates::ExecutePart1(std::vector<Coord> coords, BoundingBox bounds)
	{
		std::map<Coord, int> areas;
		for (int y = bounds.YMin; y <= bounds.YMax; ++y)
		{
			for (int x = bounds.XMin; x <= bounds.XMax; ++x)
			{
				Coord point(x, y);

				auto closestPoint = std::min_element(coords.begin(), coords.end(), 
					[&point](const Coord& c1, const Coord& c2) { return c1.GetDistanceTo(point) < c2.GetDistanceTo(point); }
				);

				// Check if there is just a single point with that distance:
				int closestDistance = point.GetDistanceTo(*closestPoint);

				int numOfClosePoints = static_cast<int>(std::count_if(coords.begin(), coords.end(), 
					[&point, closestDistance](const Coord& c) { return c.GetDistanceTo(point) == closestDistance; }
				));

				if (numOfClosePoints == 1)
				{
					// If the current point lies on the bounding border, the resulting area around its closest point will be infinite:
					if (x == bounds.XMin || x == bounds.XMax || y == bounds.YMin || y == bounds.YMax)
					{
						areas[*closestPoint] = INFINITE_AREA;
					}
					else
					{
						// Otherwise, check if this point already exists:
						auto entry = areas.find(*closestPoint);

						// If it doesn't, add to the area or increase if it hasn't been set to 'infinity' already:
						if (entry == areas.end())
							areas[*closestPoint] = 1;
						else if (entry->second != INFINITE_AREA)
							++entry->second;
					}
				}
			}
		}

		// Find largest area that isn't infinite:
		return static_cast<uint64_t>(std::max_element(areas.begin(), areas.end(),
			[](const auto& a1, const auto a2) { return a1.second < a2.second; }
		)->second);
	}

	uint64_t ChronalCoordinates::ExecutePart2(std::vector<Coord> coords, BoundingBox bounds)
	{
		uint64_t totalArea = 0;

		for (int y = bounds.YMin; y <= bounds.YMax; ++y)
		{
			for (int x = bounds.XMin; x <= bounds.XMax; ++x)
			{
				Coord point(x, y);

				int totalDistance = std::accumulate(coords.begin(), coords.end(), 0,
					[&point](int totalDist, const Coord& c) { return totalDist + c.GetDistanceTo(point); }
				);

				if (totalDistance < m_distanceLimit)
					++totalArea;
			}
		}

		return totalArea;
	}
}
