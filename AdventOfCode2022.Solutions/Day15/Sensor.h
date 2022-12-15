#pragma once
#include "Point.h"

namespace AdventOfCode::Year2022::Day15
{
	class Sensor
	{
	public:
		Point<int64_t> Pos;
		Point<int64_t> ClosestBeacon;

		int64_t SignalRadius() const
		{
			return Pos.DistanceTo(ClosestBeacon);
		}
	};
}
