#pragma once
#include "DayT.h"
#include "CubeGameProcessor.h"

namespace AdventOfCode::Year2023::Day02
{
	// ---------------------------------------------------------------------------
	// Day02: Cube Conundrum
	// ---------------------------------------------------------------------------
	class CubeConundrum : public DayT<CubeGameProcessor>
	{
	public:
		CubeConundrum();

	protected:
		uint64_t ExecutePart1(std::vector<GameRecord> gameRecords) override;
		uint64_t ExecutePart2(std::vector<GameRecord> gameRecords) override;
	};
}
