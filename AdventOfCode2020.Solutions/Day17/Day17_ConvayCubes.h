#pragma once
#include "DayT.h"
#include "CubeCoords.h"
#include "CubeProcessor.h"

namespace AdventOfCode::Year2020::Day17
{
	class ConvayCubes : public DayT<CubeCoords, CubeProcessor>
	{
	public:
		ConvayCubes(int cycles);

	protected:
		uint64_t ExecutePart1(std::vector<CubeCoords> activeCubes) override;

	private:
		int m_cycles;
	};
}

