#pragma once
#include "Point.h"

namespace AdventOfCode::Year2023::Day14
{
	enum class RockType
	{
		Cube,
		Round
	};

	class Rock
	{
	public:
		Point<int> Location;
		RockType Type;
	};
}
