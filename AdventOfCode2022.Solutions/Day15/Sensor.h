#pragma once
#include "Point.h"

namespace AdventOfCode::Year2022::Day15
{
	class Sensor
	{
	public:
		Point Pos;
		Point ClosestBeacon;

		int64_t SignalRadius() const
		{
			return Pos.DistanceTo(ClosestBeacon);
		}
	};
}
