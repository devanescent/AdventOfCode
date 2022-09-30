#pragma once
#include "DayTC.h"
#include "CoordinateProcessor.h"

namespace AdventOfCode::Year2018::Day06
{
	// ---------------------------------------------------------------------------
	// Day06: Chronal Coordinates
	// ---------------------------------------------------------------------------
	class ChronalCoordinates : public DayTC<CoordinateProcessor>
	{
	public:
		ChronalCoordinates(int distanceLimit = 10000);

		uint64_t ExecutePart1(std::vector<Coord> coords, BoundingBox bounds);
		uint64_t ExecutePart2(std::vector<Coord> coords, BoundingBox bounds);

	private:
		int m_distanceLimit;
	};
}