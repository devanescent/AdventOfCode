#pragma once
#include "Day.h"

namespace AdventOfCode::Year2020::Day03
{
	class TobogganTrajectory : public Day<>
	{
	public:
		TobogganTrajectory();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> mapData) override;
		uint64_t ExecutePart2(std::vector<std::string> mapData) override;

	private:
		int CountTreesOnTraversal(const std::vector<std::string>& map, int dx, int dy);
	};
}