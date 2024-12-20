#pragma once
#include "DayT.h"
#include "GridMapProcessor.h"

namespace AdventOfCode::Year2024::Day20
{
	// ---------------------------------------------------------------------------
	// Day20: Race Condition
	// ---------------------------------------------------------------------------
	class RaceCondition : public DayT<GridMapProcessor>
	{
	public:
		RaceCondition();
		void SetCheatMinTimeSaved(int minTimeSaved) { _minTimeSaved = minTimeSaved; }

	protected:
		uint64_t ExecutePart1(GridMap racetrack) override;
		uint64_t ExecutePart2(GridMap racetrack) override;

	private:
		int _minTimeSaved = 100;

		uint64_t CountCheats(const std::vector<Point<int>>& path, int maxDistance);
	};
}
