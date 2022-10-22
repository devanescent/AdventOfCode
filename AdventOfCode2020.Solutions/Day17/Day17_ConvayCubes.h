#pragma once
#include "DayT.h"
#include "CubeCoords.h"
#include "CubeProcessor.h"

namespace AdventOfCode::Year2020::Day17
{
	class ConvayCubes : public DayT<CubeProcessor>
	{
	public:
		ConvayCubes();

	protected:
		uint64_t ExecutePart1(std::vector<CubeCoords> activeCubes) override;
		uint64_t ExecutePart2(std::vector<CubeCoords> activeCubes) override;
	};
}

