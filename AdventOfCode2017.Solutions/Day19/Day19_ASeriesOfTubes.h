#pragma once
#include "Day.h"
#include "Point.h"

namespace AdventOfCode::Year2017::Day19
{
	// ---------------------------------------------------------------------------
	// Day19: A Series of Tubes
	// ---------------------------------------------------------------------------
	class ASeriesOfTubes : public Day<>
	{
	public:
		ASeriesOfTubes();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;

	private:
		bool MoveStep(std::vector<std::string>& grid, Point<int>& currentPos, int& dx, int& dy, std::string& letters);
	};
}
