#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2021::Day11
{
	class DumboOctopus : public DayT<std::vector<int>, IntArrayProcessor>
	{
	public:
		DumboOctopus();

	protected:
		uint64_t ExecutePart1(std::vector<std::vector<int>> heatMap) override;
		uint64_t ExecutePart2(std::vector<std::vector<int>> heatMap) override;

	private:
		void Flash(std::vector<std::vector<int>>& octopuses, int x, int y);
	};
}