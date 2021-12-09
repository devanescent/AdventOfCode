#include "Day05_HydrothermalVenture.h"
#include <algorithm>
#include <map>

namespace AdventOfCode::Year2021::Day05
{
	HydrothermalVenture::HydrothermalVenture() : DayT(5, "Hydronthermal Venture") {}

	uint64_t HydrothermalVenture::ExecutePart1(std::vector<HydroVentLine> vents)
	{
		// Consider only horizontal or vertical lines:
		return GetNumberOfIntersections(vents, [](const HydroVentLine& vent) { return vent.IsHorizontal() || vent.IsVertical(); });
	}

	uint64_t HydrothermalVenture::ExecutePart2(std::vector<HydroVentLine> vents)
	{
		// All lines, diagonal lines also:
		return GetNumberOfIntersections(vents, [](const HydroVentLine& vent) { return true; });
	}

	uint64_t HydrothermalVenture::GetNumberOfIntersections(const std::vector<HydroVentLine>& vents, std::function<bool(const HydroVentLine&)> pred)
	{
		// Collect all points from all vent lines:
		std::map<std::pair<int, int>, int> allPoints;

		for (const auto& ventLine : vents)
		{
			if (pred(ventLine))
			{
				auto linePoints = ventLine.GetAllPoints();
				std::for_each(linePoints.begin(), linePoints.end(), [&allPoints](auto& point) { ++allPoints[point]; });
			}
		}

		// Count how many points were crossed more than once:
		return std::count_if(allPoints.begin(), allPoints.end(), [](const auto& mapEntry) { return mapEntry.second > 1; });
	}
}